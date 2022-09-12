/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TCPListener.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:53:53 by mxu               #+#    #+#             */
/*   Updated: 2022/06/16 13:24:52 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCPLISTENER_HPP_
#define TCPLISTENER_HPP_

#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <string>
#include <cstring>

#include "ServerClient.hpp"

class TCPListener : public ServerGroup, public ClientGroup
{
protected:
    fd_set          masterfd;
   // fd_set          masterfd_write;
    int             max_fd;
    
    virtual void    http_server(std::string& client_request, int client_id);
    void            sendToClient(const std::string& server_response, int length, int client_id);

public:
    TCPListener() : ServerGroup(), ClientGroup() {}
    ~TCPListener();

    void            init();
    void            run();

private:
    void            _init_masterfd();
    void            _clear_masterfd();
    void            _onServerConnected(const std::string& current_server_ipAddress, int current_server_port, int current_server_socket);
    void            _onClientConnected(int client_socket_heard, const sockaddr_in& client_sockaddr_heard);
    void            _onClientDisconnected(int current_client_socket);
};

const MyException exception_ServerSocketError("Can't create a socket for the server!");
const MyException exception_ServerBindError("Server can't bind to IP/port!");
const MyException exception_ServerListenError("Server can't listen at the socket!");
const MyException exception_ServerNoBlockError("Server non-blocking error!");
const MyException exception_ServerSetSocketOptError("Server set socket option error!");

#endif