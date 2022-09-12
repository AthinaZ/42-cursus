/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerClient.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:47:56 by mxu               #+#    #+#             */
/*   Updated: 2022/06/19 14:35:27 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCLIENT_HPP_
#define SERVERCLIENT_HPP_

#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <iterator>
#include <cstring> //memset
#include <cstdlib> //atoi

#include "Implementation_spec.hpp"

struct  Location
{
    std::string                             location_pathname;
    std::map<std::string, std::string>      location_directives;
};

class Server
{
protected:
    // tcp communication configuration
    std::string                             server_ipAddress;
    int                                     server_port;
    int                                     server_socket;
    sockaddr_in                             server_sockaddr;

    // data parsed from web server conf file
    std::map<std::string, std::string>      server_directives;
    std::map<int, std::string>              server_error_page_location;
    std::vector<Location>                   server_locations;

public:
    Server(const std::string& ipAddress, int port) :
        server_ipAddress(ipAddress), server_port(port) {}
    Server(std::map<std::string, std::string> param, std::map<int, std::string> err_page, std::vector<Location> loc);
    ~Server();

friend class ServerGroup;
friend class TCPListener;
friend class WebServer;
};

class ServerGroup
{
protected:
    std::vector<Server*>                    server_group;

    // configuration data
    std::string                             raw_config_file;

public:
    ServerGroup() {};
    ~ServerGroup();
    void                                    simple_config(std::string ipAddress, int port);
    void                                    parse_config(int ac, char** av);
    void                                    AddServer(std::string ipAddress, int port);
    void                                    AddServer(std::map<std::string, std::string> param, std::map<int, std::string> err_page, std::vector<Location> loc);

public:
    // utility functions
    bool                                    read_file(const std::string& file_name, std::string& raw_record);
    bool                                    write_file(const std::string& file_name, const std::string& raw_record, int n);
    void                                    split_first_line(std::istringstream& input_stream, std::vector<std::string>& output_vector);

private:
    std::string                             _verify_input(int ac, char** av);
    void                                    _parse_server_config(const std::string& conf_file);
    int                                     _check_name(const std::string& name);
    bool                                    _server_param_check(const std::map<std::string, std::string>& param);
    bool                                    _check_server_redundancy();
};

class MyException : public std::exception
{
    const std::string   _text;

    MyException();

public:
    MyException(const std::string &  error_message) : _text(error_message) {};
    ~MyException() throw() {};
    const char *    what() const throw() { return _text.c_str(); };
};

const MyException exception_ToManyArgError("Too many input arguments, only conf file path for the webserver is necessary!");
const MyException exception_ReadConfFileError("Error reading server configuration file!");
const MyException exception_NoServerError("No server found in the conf file!");
const MyException exception_NameParseError("Found unknown directive in the conf file!");
const MyException exeption_ServerParamError("Did not find either 'listen' or 'server_name' parameter in the conf file!");
const MyException exception_ServerRedundancyError("There are two servers serving at the same IP address/port!");

struct  client_headline
{
    std::string     method;
    std::string     uri;
    std::string     protocol;
};

struct  server_headline
{
    std::string     protocol;
    int             code;
    std::string     status;
};

class Client
{
protected:
    // tcp communication configuration
    std::string                             client_ipAddress;
    int                                     client_port;
    int                                     client_socket;
    sockaddr_in                             client_sockaddr;

    // tcp data
    bool                                    current_in_connection;
    bool                                    request_pending;

    // http data
    std::string                             client_raw_request;
    client_headline                         client_request_headline;
    std::map<std::string, std::string>      client_request_header;
    std::string                             client_request_body;
    server_headline                         server_response_headline;
    std::map<std::string, std::string>      server_response_header;
    std::string                             server_response_body;

public:
    Client() {}
    Client(int client_socket_heard, const sockaddr_in& client_sockaddr_heard);
    ~Client();

    void                                    clear_client_request();
    void                                    clear_server_response();

friend class TCPListener;
friend class WebServer;
};

class ClientGroup
{
protected:
    std::vector<Client*> client_group;

public:
    ClientGroup() {}
    ~ClientGroup();
    void                                    AddClient(int client_socket_heard, const sockaddr_in& client_sockaddr_heard);
};

#endif
