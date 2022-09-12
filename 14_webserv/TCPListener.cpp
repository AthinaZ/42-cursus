/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TCPListener.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:14:04 by mxu               #+#    #+#             */
/*   Updated: 2022/06/19 15:18:39 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TCPListener.hpp"
#include <strings.h> // ubuntu needed this lib for bcopy
// ubuntu needed this defined to eliminate error: 'FD_COPY' was not declared in this scope
// macOS is fine with this addition below
#ifndef FD_COPY
#define FD_COPY(f, t)   __DARWIN_FD_COPY(f, t)
#endif
#define __DARWIN_FD_COPY(f, t)  bcopy(f, t, sizeof(*(f)))

// TCP listener class

TCPListener::~TCPListener() {}

void            TCPListener::init()
{
    for (size_t i = 0; i < server_group.size(); ++i)
    {
        // make alias for names
        std::string&    current_server_ipAddress = server_group[i]->server_ipAddress;
        int&            current_server_port = server_group[i]->server_port;
        int&            current_server_socket = server_group[i]->server_socket;
        sockaddr_in&    current_server_sockaddr = server_group[i]->server_sockaddr;

        // create a socket
        current_server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (current_server_socket == -1)
            throw exception_ServerSocketError;

        // set noblock
        if (fcntl(current_server_socket, F_SETFL, O_NONBLOCK) == -1)
            throw exception_ServerNoBlockError;

        // set option
        int opt = 1;
        if (setsockopt(current_server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
            throw exception_ServerSetSocketOptError;

        // bind the ip address and the port of the server to the socket created
        current_server_sockaddr.sin_family = AF_INET;
        current_server_sockaddr.sin_port = htons(current_server_port);
        //current_server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        inet_pton(AF_INET, current_server_ipAddress.c_str(), &current_server_sockaddr.sin_addr);
        if (bind(current_server_socket, (sockaddr*) &current_server_sockaddr, sizeof(current_server_sockaddr)) == -1)
            throw exception_ServerBindError;

        // start listening
        if (listen(current_server_socket, SOMAXCONN) == -1)
            throw exception_ServerListenError;

        _onServerConnected(current_server_ipAddress, current_server_port, current_server_socket);
    }
}

void            TCPListener::run()
{
    _init_masterfd();

    bool    running = true;
    int     j = 0;
    fd_set  select_read;
    fd_set  select_write;

    while(running)
    {
        std::cout << "j = " << j << std::endl << std::endl;

        FD_COPY(&masterfd, &select_read);
        FD_COPY(&masterfd, &select_write);

        // select only interacting sockets, i.e.,
        // select() works when client makes a request for connection:
        // "A readable event will be delivered when a new connection is attempted
        // and you may then call accept() to get a socket for that connection."
        struct timeval  time_out = {10, 0};
        int     select_count = select(max_fd + 1, &select_read, &select_write, 0, &time_out);
        std::cout << "select_count = " << select_count << std::endl << std::endl;

        // loop through all servers to see if there are new client requests for connections
        for (size_t i = 0; i < server_group.size(); ++i)
        {
            int&            current_server_socket = server_group[i]->server_socket;

            // std::cout << "select_count = " << select_count << std::endl;
            // std::cout << "FD_ISSET test: server in select_read " << FD_ISSET(current_server_socket, &select_read) << std::endl;
            // std::cout << "FD_ISSET test: server in select_write " << FD_ISSET(current_server_socket, &select_write) << std::endl;

            if (FD_ISSET(current_server_socket, &select_read) /* && gia_client == false */)
            {
                int             client_socket_heard;
                sockaddr_in     client_sockaddr_heard;
                socklen_t       clientSize = sizeof(client_sockaddr_heard);
                int             heard  = accept(current_server_socket, (sockaddr*) &client_sockaddr_heard, &clientSize);
                if (heard != -1)
                {
                    client_socket_heard = heard;
                    fcntl(client_socket_heard, F_SETFL, O_NONBLOCK);
                    FD_SET(client_socket_heard, &masterfd);
                    max_fd = ((client_socket_heard > max_fd) ? client_socket_heard : max_fd);
                    std::cout << "max_fd = " << max_fd << std::endl << std::endl;
                    _onClientConnected(client_socket_heard, client_sockaddr_heard);
                    //current_in_connection = true;
                }
            }
        }

        // loop through all clients to serve the web content
        for (size_t i = 0; i < client_group.size(); ++i)
        {
            int&            current_client_socket = client_group[i]->client_socket;
            bool&           current_request_pending = client_group[i]->request_pending;
            std::string&    current_client_raw_request = client_group[i]->client_raw_request;

            // std::cout << "select_count = " << select_count << std::endl;
            // std::cout << "FD_ISSET test: client in select_read " << FD_ISSET(current_client_socket, &select_read) << std::endl;
            // std::cout << "FD_ISSET test: client in select_write " << FD_ISSET(current_client_socket, &select_write) << std::endl << std::endl;

            if (FD_ISSET(current_client_socket, &select_read) && current_request_pending == false)
            {
                std::cout << "Hey you!" <<  std::endl << std::endl;
                char buf[4096];
                memset(buf, 0, 4096);
                int bytesIn = recv(current_client_socket, buf, 4096, 0);
                std::cout << "bytesIn = " << bytesIn << std::endl << std::endl;
                if (bytesIn <= 0)
                {
                    _onClientDisconnected(current_client_socket);
                    break;
                }
                else
                {
                    current_client_raw_request = buf;
                    FD_SET(current_client_socket, &masterfd);
                    FD_CLR(current_client_socket, &masterfd);
                    current_request_pending = true;
                }
            }

            if (FD_ISSET(current_client_socket, &select_write) && current_request_pending == true)
            {
                std::cout << "Hey me!" <<  std::endl << std::endl;
                http_server(current_client_raw_request, i); // parse and http serve
                FD_SET(current_client_socket, &masterfd);
                FD_CLR(current_client_socket, &masterfd);
                current_request_pending = false;
            }
        }

        // if (j == 10)
        //     break;
        j++;
    }

    _clear_masterfd();
}

void            TCPListener::_onServerConnected(const std::string& current_server_ipAddress, int current_server_port, int current_server_socket)
{
    std::cout << "Server is listening at socket = " << current_server_socket << " ipAddress = "
        << current_server_ipAddress << " port = " << current_server_port << std::endl << std::endl;
}

void            TCPListener::_onClientConnected(int client_socket_heard, const sockaddr_in& client_sockaddr_heard)
{
    AddClient(client_socket_heard, client_sockaddr_heard);

    std::cout << "Client is connected at socket = " << client_socket_heard
        << " host = " << client_group.back()->client_ipAddress
        << " port = " << client_group.back()->client_port << std::endl << std::endl;
}

void            TCPListener::_onClientDisconnected(int current_client_socket)
{
    std::cout << "Client disconnected at socket " << current_client_socket << std::endl << std::endl;
}

void            TCPListener::_init_masterfd()
{
    // create the master I/O descriptor set and initialize to zero
    FD_ZERO(&masterfd);
   // FD_ZERO(&masterfd_write);
    max_fd = 0;

    // first of all, store the server listening socket
    for (size_t i = 0; i < server_group.size(); ++i)
    {
        int&            current_server_socket = server_group[i]->server_socket;

        FD_SET(current_server_socket, &masterfd);
       // FD_SET(current_server_socket, &masterfd_write);
        max_fd = ((current_server_socket > max_fd) ? current_server_socket : max_fd);
        std::cout << "max_fd = " << max_fd << std::endl << std::endl;
    }
}

void            TCPListener::_clear_masterfd()
{
    // close all sockets
    for (size_t i = 0; i < server_group.size(); ++i)
    {
        int&    current_server_socket = server_group[i]->server_socket;
        FD_CLR(current_server_socket, &masterfd);
        //FD_CLR(current_server_socket, &masterfd_write);
        close(current_server_socket);
    }

    for (size_t i = 0; i < client_group.size(); ++i)
    {
        int&    current_client_socket = client_group[i]->client_socket;
        FD_CLR(current_client_socket, &masterfd);
        //FD_CLR(current_client_socket, &masterfd_write);
        close(current_client_socket);
    }
}

void            TCPListener::http_server(std::string& client_request, int client_id)
{ (void) client_request; (void) client_id; }

void            TCPListener::sendToClient(const std::string& server_response, int length, int client_id)
{
    int&            current_client_socket = client_group[client_id]->client_socket;

    int bytesOut = send(current_client_socket, server_response.c_str(), length, 0);

    std::cout << "bytesOut = " << bytesOut << std::endl << std::endl;
}
