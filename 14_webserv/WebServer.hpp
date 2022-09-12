/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:47:25 by mxu               #+#    #+#             */
/*   Updated: 2022/06/18 20:07:05 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER_HPP_
#define WEBSERVER_HPP_

#include "TCPListener.hpp"
#include <cstdlib>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h> 

class WebServer : public TCPListener
{
public:
    WebServer() : TCPListener() {}
    ~WebServer() {}

    void                parse_request(std::string& client_request, int client_id);
    void                generate_response(int client_id);
    void                http_server(std::string& client_request, int client_id);
    bool                image_exists(std::string file);
    bool                image_ext(const std::string& file);

private:
    void                _set_client_request_headline(std::istringstream& iss, int client_id);
    void                _set_client_request_header(std::istringstream& iss, int client_id);
    void                _set_client_request_body(std::string& client_request, int client_id);

    void                _set_server_response_headline(int client_id, int error_code);
    void                _set_server_response_header(int client_id, int error_code);
    int                 _set_server_response_body(int client_id);
    void                _compose_response(std::string& server_response, int client_id);

    int                 _GET(int client_id);
    int                 _POST(int client_id);
    int                 _DELETE(int client_id);

    int                 _match_server(int client_id);
    int                 _match_location(int client_id, int server_id);
    const std::string   _request_file_path(int client_id);
    const std::string   _request_file_path(int client_id, bool& autoindex);
    const std::string   _error_file_path(int client_id, int error_code);
    bool                _check_existing_error_page(int client_id, int error_code);
    std::string         _error_code_to_string(int error_code);
    const std::string   _errorcode_name(int error_code);
    void                _serve_error_page(int client_id, int error_code, std::string& response_body);
    int                 _check_method(const std::string& method_name);
    bool                _autoindex_file(const std::string& directory_name, std::string& response_body);
    char**              _split_query_string(std::string& whole_query, std::map<std::string, std::string>& split_query);
    int                 _cgi_POST(int client_id, const std::string& query);
    int                 _cgi_GET(int client_id, std::string& query);
    char**              _set_command(int client_id);
    int                 _fileUpload(int client_id);
    void                _clean(char** var);
};

#endif
