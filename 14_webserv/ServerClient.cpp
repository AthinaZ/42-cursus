/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerClient.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:36:46 by mxu               #+#    #+#             */
/*   Updated: 2022/06/19 15:25:45 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerClient.hpp"

// Server

Server::Server(std::map<std::string, std::string> param, std::map<int, std::string> err_page, std::vector<Location> loc) :
        server_directives(param), server_error_page_location(err_page), server_locations(loc)
{
    // The standard form is "listen  127.0.0.1:8080"
    // We assume that our servers listen on all ip address, i.e.,  "8080" means "0.0.0.0:8080"
    std::string listen_param = param.find("listen")->second;
    size_t      seperator_pos = listen_param.find(':');
    std::string ipPart = listen_param.substr(0, seperator_pos);
    std::string portPart = listen_param.substr(seperator_pos + 1);
    server_ipAddress = (seperator_pos != std::string::npos) ? ipPart : "0.0.0.0";
    server_port = (seperator_pos != std::string::npos) ? atoi(portPart.c_str()) : atoi(listen_param.c_str());

    for (std::map<std::string, std::string>::iterator i = server_directives.begin(); i != server_directives.end(); ++i)
        std::cout << "server directive name = " << i->first << ";  parameter = " << i->second << std::endl;
    std::cout << std::endl;

    for (std::vector<Location>::iterator i = server_locations.begin(); i != server_locations.end(); ++i)
    {
        std::cout << "location path = " << i->location_pathname << std::endl << std::endl;
        for (std::map<std::string, std::string>::iterator j = i->location_directives.begin(); j != i->location_directives.end(); ++j)
            std::cout << "location directive name = " << j->first << ";  parameter = " << j->second << std::endl;
        std::cout << std::endl;
    }
}

Server::~Server() {}

// ServerGroup

ServerGroup::~ServerGroup()
{
    for (size_t i = 0; i < server_group.size(); ++i)
        delete server_group[i];
}

void    ServerGroup::simple_config(std::string ipAddress, int port)
{
    AddServer(ipAddress, port);
}

void    ServerGroup::parse_config(int ac, char** av)
{
    std::string conf_file;

    conf_file = _verify_input(ac, av);
    _parse_server_config(conf_file);
}

std::string    ServerGroup::_verify_input(int ac, char** av)
{
    if (ac > 2)
        throw exception_ToManyArgError;
    if (ac == 2)
        return av[1];
    else
        return default_config_file;
}

bool    ServerGroup::read_file(const std::string& file_name, std::string& raw_record)
{
    bool    ret = false;

    std::ifstream   in_file(file_name.c_str(), std::ifstream::in);
    if (in_file)
    {
        std::ostringstream content;
        content << in_file.rdbuf();
        in_file.close();
        raw_record = content.str();
        ret = true;
    }
    return ret;
}

bool    ServerGroup::write_file(const std::string& file_name, const std::string& raw_record, int n)
{
    bool    ret = false;

    std::ofstream out_file(file_name.c_str(), std::ofstream::out);
    if (out_file)
    {
        out_file.write(raw_record.c_str(), n);
        out_file.close();
        ret = true;
    }
    return ret;
}

void    ServerGroup::split_first_line(std::istringstream& input_stream, std::vector<std::string>& output_vector)
{
    std::string                         line;
    std::getline(input_stream, line);
    std::istringstream                  issline(line);
    std::istream_iterator<std::string>  last;
    std::istream_iterator<std::string>  first(issline);
    std::vector<std::string>            parsed(first, last);
    //std::vector<std::string>    parsed((std::istream_iterator<std::string>(issline)), std::istream_iterator<std::string>());
    output_vector.clear();
    output_vector = parsed;
}

// We make simplied assumptions that:
//
// 1. we consider only "server" and "location" blocks, implicitly assuming the context of "http"
//
// 2. the first line for each "server" block is of the form "server {"
// 3. a separate line with "}" to close off a server configuration
// for example:
// server {
// # the default location
// root /var/www/html;
// }
// 4. note that a line that starts with '#' is skipped as comments
// 5. each line inside the "server" block is composed of a directive name (root) and a parameter (/var/www/html), end with ";"
//
// 6. similer rule holds for the location block
// for example:
// location /images {
// autoindex on;
// }
//
// 7. we check that the server configuration contains at least "listen" and "server_name" directives
// 8. allowed directives are listed in Server_Conf from Implementation_spec.hpp

void    ServerGroup::_parse_server_config(const std::string& conf_file)
{
    if (!read_file(conf_file, raw_config_file))
        throw exception_ReadConfFileError;

    std::istringstream          iss(raw_config_file);
    std::vector<std::string>    parsed_line;
    int                         brackets = 0;

    while(!iss.eof())
    {
        split_first_line(iss, parsed_line);
        if (parsed_line.size() == 0 || parsed_line[0][0] == '#')
            continue;
        if (parsed_line[0] == "server" && parsed_line[1] == "{")
        {
            brackets = 1;
            std::map<std::string, std::string>  server_param;
            std::map<int, std::string>          server_err_page;
            std::vector<Location>               server_loc;
            while(brackets > 0)
            {
                split_first_line(iss, parsed_line);
                if (parsed_line.size() == 0 || parsed_line[0][0] == '#')
                    continue;
                if (parsed_line[0] == "}")
                {
                    if (!_server_param_check(server_param))
                        throw exeption_ServerParamError;
                    AddServer(server_param, server_err_page, server_loc);
                    brackets = 0;
                    continue;
                }
                //if (_check_name(parsed_line[0]) == -1 )
                //    throw exception_NameParseError;
                else if (_check_name(parsed_line[0]) == server_location)
                {
                    brackets = 2;
                    Location    one_location;
                    one_location.location_pathname = parsed_line[1];
                    while (brackets > 1)
                    {
                        split_first_line(iss, parsed_line);
                        if (parsed_line.size() == 0 || parsed_line[0][0] == '#')
                            continue;
                        if (parsed_line[0] == "}")
                        {
                            server_loc.push_back(one_location);
                            brackets = 1;
                            continue;
                        }
                        //if (_check_name(parsed_line[0]) == -1 )
                        //    throw exception_NameParseError;
                        else
                        {
                            if (parsed_line[1][parsed_line[1].size() - 1] == ';')
                                parsed_line[1].erase(parsed_line[1].size() - 1);
                            one_location.location_directives.insert(std::pair<std::string, std::string>(parsed_line[0], parsed_line[1]));
                        }
                    }
                }
                else
                {
                    if (parsed_line[1][parsed_line[1].size() - 1] == ';')
                        parsed_line[1].erase(parsed_line[1].size() - 1);
                    server_param.insert(std::pair<std::string, std::string>(parsed_line[0], parsed_line[1]));
                    if (parsed_line[0] == "error_page")
                    {
                        if (parsed_line[2][parsed_line[2].size() - 1] == ';')
                            parsed_line[2].erase(parsed_line[2].size() - 1);
                        server_err_page.insert(std::pair<int, std::string>(atoi(parsed_line[1].c_str()), parsed_line[2]));
                    }
                }
            }
        }
    }

    if (server_group.size() == 0)
        throw exception_NoServerError;

    if (_check_server_redundancy())
        throw exception_ServerRedundancyError;
}

int     ServerGroup::_check_name(const std::string& name)
{
        if (name == "server_name")  return server_server_name;
        if (name == "listen")       return server_listen;
        if (name == "root")         return server_root;
        if (name == "index")        return server_index;
        if (name == "autoindex")    return server_autoindex;
        if (name == "location")     return server_location;
        if (name == "error_page")   return server_error_page;
        return -1;
}

bool    ServerGroup::_server_param_check(const std::map<std::string, std::string>& param)
{
    if (param.find("listen") != param.end() && param.find("server_name") != param.end())
        return true;
    else
        return false;
}

bool    ServerGroup::_check_server_redundancy()
{
    bool    ret = false;

    if (server_group.size() == 1)
        return ret;
    for (size_t i = 0; i < server_group.size() - 1; ++i)
    {
        Server* current_server = server_group[i];
        for (size_t j = i + 1; j < server_group.size(); ++j)
        {
            Server* follow_server = server_group[j];
            if ((current_server->server_ipAddress == follow_server->server_ipAddress ||
                current_server->server_ipAddress == "0.0.0.0" ||
                follow_server->server_ipAddress == "0.0.0.0") &&
                current_server->server_port == follow_server->server_port)
            ret = true;
            std::cout << "i = " << i << "; j = " << j << std::endl;
        }
    }
    return ret;
}

void    ServerGroup::AddServer(std::string ipAddress, int port)
{
    Server* newServer = new Server(ipAddress, port);

    server_group.push_back(newServer);
}

void    ServerGroup::AddServer(std::map<std::string, std::string> param, std::map<int, std::string> err_page, std::vector<Location> loc)
{
    Server* newServer = new Server(param, err_page, loc);
    server_group.push_back(newServer);
}

// Client

Client::Client(int client_socket_heard, const sockaddr_in& client_sockaddr_heard)
{
    client_socket = client_socket_heard;
    client_sockaddr = client_sockaddr_heard;

    char host[NI_MAXHOST];
    memset(host, 0, NI_MAXHOST);
    inet_ntop(AF_INET, &client_sockaddr_heard.sin_addr, host, NI_MAXHOST);
    client_ipAddress = host;

    client_port = ntohs(client_sockaddr_heard.sin_port);

    current_in_connection = false;
    request_pending = false;
}

Client::~Client() {}

void                Client::clear_client_request()
{
    client_request_headline.method.clear();
    client_request_headline.uri.clear();
    client_request_headline.protocol.clear();
    client_request_header.clear();
    client_request_body.clear();
}

void                Client::clear_server_response()
{
    server_response_headline.protocol.clear();
    server_response_headline.code = 0;
    server_response_headline.status.clear();
    server_response_header.clear();
    server_response_body.clear();
}

// ClientGroup

ClientGroup::~ClientGroup()
{
    for (size_t i = 0; i < client_group.size(); ++i)
        delete client_group[i];
}

void    ClientGroup::AddClient(int client_socket_heard, const sockaddr_in& client_sockaddr_heard)
{
    Client* newClient = new Client(client_socket_heard, client_sockaddr_heard);

    client_group.push_back(newClient);
}
