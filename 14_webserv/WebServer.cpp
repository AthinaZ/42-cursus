/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:52:34 by mxu               #+#    #+#             */
/*   Updated: 2022/06/19 14:46:31 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServer.hpp"

void    WebServer::http_server(std::string& client_request, int client_id)
{
    parse_request(client_request, client_id);
    generate_response(client_id);

    std::string server_response;
    _compose_response(server_response, client_id);
    sendToClient(server_response, server_response.size() + 1, client_id);
}

void    WebServer::parse_request(std::string& client_request, int client_id)
{
    client_group[client_id]->clear_client_request();

    // We seperate the client request into three parts: e.g.
    // headline:    GET / HTTP/1.1
    // header:      Host: localhost:8080, etc
    // body:        the content of the body
    _set_client_request_body(client_request, client_id);
    std::istringstream  iss(client_request);
    _set_client_request_headline(iss, client_id);
    _set_client_request_header(iss, client_id);
}

void    WebServer::generate_response(int client_id)
{
    client_group[client_id]->clear_server_response();

    // We seperate the server response into three parts: e.g.
    // headline:    HTTP/1.1 200 OK
    // header:      Cache-Control: no-cache, private, etc
    // body:        the content of the body
    int     error_code;
    error_code = _set_server_response_body(client_id);
    _set_server_response_headline(client_id, error_code);
    _set_server_response_header(client_id, error_code);
}

void    WebServer::_set_client_request_body(std::string& client_request, int client_id)
{
    std::string&    current_client_request_body = client_group[client_id]->client_request_body;

    size_t  seperator_pos = client_request.find("\r\n\r\n");
    if(seperator_pos != std::string::npos && seperator_pos + 4 != std::string::npos)
    {
        current_client_request_body = client_request.substr(seperator_pos + 4);
        client_request.erase(seperator_pos, std::string::npos);
    } else
    {
        current_client_request_body = "";
    }
}

void    WebServer::_set_client_request_headline(std::istringstream& iss, int client_id)
{
    client_headline&    current_client_request_headline = client_group[client_id]->client_request_headline;

    std::vector<std::string>    parsed;
    split_first_line(iss, parsed);

    current_client_request_headline.method = parsed[0];
    current_client_request_headline.uri = parsed[1];
    current_client_request_headline.protocol = parsed[2];
    std::cout << parsed[0] << " " << parsed[1] << " " << parsed[2] << std::endl << std::endl;
}

void    WebServer::_set_client_request_header(std::istringstream& iss, int client_id)
{
    std::map<std::string, std::string>&    current_client_request_header = client_group[client_id]->client_request_header;

    while (1)
    {
        std::string     nextline;
        std::getline(iss, nextline);
        if (nextline.size() == 0)
            break;
        size_t          seperator_pos = nextline.find(':');
        std::string     key = nextline.substr(0, seperator_pos);
        std::string     value = nextline.substr(seperator_pos + 2);
        current_client_request_header.insert(std::pair<std::string, std::string>(key, value));
    }
    for (std::map<std::string, std::string>::iterator it = current_client_request_header.begin(); it != current_client_request_header.end(); ++it)
        std::cout << "key = " << it->first << " value = " << it->second << std::endl << std::endl;
    std::cout << "number of pairs = " << current_client_request_header.size() << std::endl << std::endl;
}

// If there are several servers that match the IP address and port of the request,
// Nginx tests the request’s Host header field against the server_name directives in the server blocks.
// We have already excluded this case with _check_server_redundancy() function when we parsed the conf file.
// Also in "ServerClient.cpp", we have assumed that our server listen on all ipAddresses "0.0.0.0".
int     WebServer::_match_server(int client_id)
{
    std::map<std::string, std::string>&    current_client_request_header = client_group[client_id]->client_request_header;

    int     ret = -1;
    for (size_t i = 0; i < server_group.size(); ++i)
    {
        Server*     current_server = server_group[i];
        std::string host_param = current_client_request_header.find("Host")->second;
        size_t      seperator_pos = host_param.find(':');
        std::string hostnamePart = host_param.substr(0, seperator_pos);
        std::string portPart = host_param.substr(seperator_pos + 1);
        std::string hostname_requested = (seperator_pos != std::string::npos) ? hostnamePart : "";
        int         port_requested = (seperator_pos != std::string::npos) ? atoi(portPart.c_str()) : atoi(host_param.c_str());

        if (current_server->server_port == port_requested)
            ret = i;
    }
    return ret;
}

// NGINX tests request URIs against the parameters of all location directives and applies the
// directives defined in the matching location. We assume the parameter to the location directive is
// a prefix string (location_pathname) and not regular expressions.
// We also assume exact match to URI in the conf file, without the "=" sign.
int     WebServer::_match_location(int client_id, int server_id)
{
    client_headline&        current_client_request_headline = client_group[client_id]->client_request_headline;
    std::vector<Location>&  current_server_locations = server_group[server_id]->server_locations;
    int                     ret = -1;
    int                     length = 0;

    for(int i = 0; i < (int)current_server_locations.size(); ++i)
    {
        std::string comp_path = current_server_locations[i].location_pathname;
        int         comp_length = comp_path.size();
        if (current_client_request_headline.uri.compare(0, comp_length, comp_path) == 0 && comp_length > length)
        {
            ret = i;
            length = comp_length;
        }
        if (comp_length == (int)current_client_request_headline.uri.size())
                break;
    }
    return ret;
}

// To obtain the path of a requested file, NGINX appends the request URI to the path specified by the root directive.
const std::string WebServer::_request_file_path(int client_id)
{
    int                                 server_id = _match_server(client_id);
    std::map<std::string, std::string>& current_server_directives = server_group[server_id]->server_directives;

    client_headline&                    current_client_request_headline = client_group[client_id]->client_request_headline;

    int                                 location_id = _match_location(client_id, server_id);

    std::map<std::string, std::string>::iterator    it = current_server_directives.find("root");
    if (location_id != -1)
    {
        std::map<std::string, std::string>& current_location_directives = server_group[server_id]->server_locations[location_id].location_directives;
        if (current_location_directives.find("root") != current_location_directives.end())
            it = current_server_directives.find("root");
    }

    size_t      seperator_pos = current_client_request_headline.uri.find('?');
    std::string filePath = (seperator_pos != std::string::npos) ?
        current_client_request_headline.uri.substr(0, seperator_pos) : current_client_request_headline.uri;

    return it->second + filePath;
}

// If a request ends with a slash, NGINX treats it as a request for a directory and tries to find an index
// file in the directory. The index directive defines the index file’s name (the default value is index.html).
// The server returns an automatically generated directory listing if the autoindex directive is set to "ON".
const std::string WebServer::_request_file_path(int client_id, bool& autoindex)
{
    int                                 server_id = _match_server(client_id);
    std::map<std::string, std::string>& current_server_directives = server_group[server_id]->server_directives;

    client_headline&                    current_client_request_headline = client_group[client_id]->client_request_headline;
    size_t                              seperator_pos = current_client_request_headline.uri.find('?');
    std::string                         filePath = (seperator_pos != std::string::npos) ?
        current_client_request_headline.uri.substr(0, seperator_pos) : current_client_request_headline.uri;

    int                                 location_id = _match_location(client_id, server_id);

    std::map<std::string, std::string>::iterator    it;
    if ( location_id == -1) // no matching location block found
    {
        it = current_server_directives.find("root");
        filePath = it->second + filePath;
        it = current_server_directives.find("index");
        filePath = (it != current_server_directives.end()) ? filePath + it->second : filePath + "index.html";
        it = current_server_directives.find("autoindex");
        if ( it != current_server_directives.end())
            autoindex = (it->second == "on") ? true : false;
    }
    else // found matching location block
    {
        std::map<std::string, std::string>& current_location_directives = server_group[server_id]->server_locations[location_id].location_directives;
        it = current_location_directives.find("root");
        if (it == current_location_directives.end())
            it = current_server_directives.find("root");
        filePath = it->second + filePath;
        it = current_location_directives.find("index");
        filePath = (it != current_location_directives.end()) ? filePath + it->second : filePath + "index.html";
        it = current_location_directives.find("autoindex");
        if ( it != current_location_directives.end())
            autoindex = (it->second == "on") ? true : false;
    }
    return filePath;
}

// We assume the conf file syntax: error_page code uri, for example "error_page 404 /404.html"
// We assume all the error_page information is in the  server context (not in the location context)
const std::string WebServer::_error_file_path(int client_id, int error_code)
{
    int                                 server_id = _match_server(client_id);
    std::map<std::string, std::string>& current_server_directives = server_group[server_id]->server_directives;
    std::map<int, std::string>&         current_server_error_page_location = server_group[server_id]->server_error_page_location;

    //std::cout  << std::endl << "error_file_path = " << current_server_directives.find("root")->second + current_server_error_page_location.find(error_code)->second << std::endl << std::endl;
    return current_server_directives.find("root")->second + current_server_error_page_location.find(error_code)->second;
}

bool    WebServer::_check_existing_error_page(int client_id, int error_code)
{
    int                                 server_id = _match_server(client_id);
    std::map<int, std::string>&         current_server_error_page_location = server_group[server_id]->server_error_page_location;

    return (current_server_error_page_location.find(error_code) != current_server_error_page_location.end()) ? true : false;
}

void    WebServer::_serve_error_page(int client_id, int error_code, std::string& response_body)
{
    if (_check_existing_error_page(client_id, error_code))
    {
        if (!read_file(_error_file_path(client_id, error_code), response_body))
            response_body = _error_code_to_string(error_code) + " " + _errorcode_name(error_code);
    }
    else
        response_body = _error_code_to_string(error_code) + " " + _errorcode_name(error_code);
}

std::string         WebServer::_error_code_to_string(int error_code)
{
    std::stringstream str;
    str << error_code;
    std::string result;
    str >> result;
    return result;
}

const std::string   WebServer::_errorcode_name(int error_code)
{
        if (error_code == Error_OK)                     return "OK";
        if (error_code == Error_Created)                return "Created";
        if (error_code == Error_No_Content)             return "No Content";
        if (error_code == Error_Moved_Permanently)      return "Moved Pernamently";
        if (error_code == Error_Not_Found)              return "Not Found";
        if (error_code == Error_Forbidden)              return "Forbidden";
        if (error_code == Error_Method_Not_Allowed)     return "Method Not Allowed";
        if (error_code == Error_Internal_Server_Error)  return "Internal Server Error";
        return "Unknown_Errorcode";
}

int     WebServer::_check_method(const std::string& method_name)
{
        if (method_name == "GET")       return HTTP_GET;
        if (method_name == "POST")      return HTTP_POST;
        if (method_name == "DELETE")    return HTTP_DELETE;
        return -1;
}

int     WebServer::_set_server_response_body(int client_id)
{
    client_headline&                current_client_request_headline = client_group[client_id]->client_request_headline;
    std::string&                    current_client_response_body = client_group[client_id]->server_response_body;

    int     ret = Error_Not_Found;

    if (_check_method(current_client_request_headline.method) == -1)
    {
        ret = Error_Method_Not_Allowed;
        _serve_error_page(client_id, ret, current_client_response_body);
    }
    else if (current_client_request_headline.method == "GET")
    {
        ret = _GET(client_id);
        std::cout << "We are using method GET!" << std::endl << std::endl;
    }
    else if (current_client_request_headline.method == "POST")
    {
        ret = _POST(client_id);
        std::cout << "We are using method POST!" << std::endl << std::endl;
    }
    else if (current_client_request_headline.method == "DELETE")
    {
        ret = _DELETE(client_id);
        std::cout << "We are using method DELETE!" << std::endl << std::endl;
    }
    return ret;
}

int     WebServer::_GET(int client_id)
{
    client_headline&                    current_client_request_headline = client_group[client_id]->client_request_headline;
    std::string&                        current_client_response_body = client_group[client_id]->server_response_body;

    int         ret = Error_Not_Found;
    bool        found_content = false;

    size_t      seperator_pos = current_client_request_headline.uri.find('?');
    std::string pathinfo_part = (seperator_pos != std::string::npos) ?
        current_client_request_headline.uri.substr(0, seperator_pos) : current_client_request_headline.uri;
    std::string query_part =  (seperator_pos != std::string::npos) ?
        current_client_request_headline.uri.substr(seperator_pos + 1) : "";

    std::cout << "The whole URI is: " << current_client_request_headline.uri << std::endl << std::endl;
    std::cout << "The pathinfo_part is: " << pathinfo_part << std::endl << std::endl;
    std::cout << "The query_part is: " << query_part << std::endl << std::endl;

    if (pathinfo_part.substr(0, 9) == "/redirect") // redirect
        ret = Error_Moved_Permanently;
    else if (pathinfo_part.substr(0, 8) != "/cgi-bin" && seperator_pos != std::string::npos)
        ret = Error_Internal_Server_Error;
    else if (pathinfo_part.substr(0, 8) == "/cgi-bin") // CGI
    {
        ret = _cgi_GET(client_id, query_part);
        if (ret == Error_OK)
            read_file("site/outfile.txt", current_client_response_body);
    }
    else if (pathinfo_part[pathinfo_part.size() - 1] == '/') // GET directory
    {
        bool    autoindex;
        found_content = read_file(_request_file_path(client_id, autoindex), current_client_response_body);
        if (found_content)
            ret = Error_OK;
        else if (!found_content && autoindex)
        {
            if (_autoindex_file(_request_file_path(client_id), current_client_response_body))
                ret = Error_OK;
            else
                ret = Error_Not_Found;
        }
        else if (!found_content && !autoindex)
            ret = Error_Forbidden;
    }
    else // GET file
    {
        found_content = read_file(_request_file_path(client_id), current_client_response_body);
        ret = ((found_content == true) ? Error_OK : Error_Not_Found);
    }

    if (ret != Error_OK)
        _serve_error_page(client_id, ret, current_client_response_body);

    return ret;
}

// Instead of an environment variable QUERY_STRING all together, we parse it before sending to the execve function.
int     WebServer::_cgi_GET(int client_id, std::string& query)
{
    std::map<std::string, std::string>  query_map;
    char**  env = _split_query_string(query, query_map);
    char**  cmd = _set_command(client_id);

    std::cout << "The query_map is: " << std::endl;
    for (std::map<std::string, std::string>::iterator it = query_map.begin(); it != query_map.end(); ++it)
        std::cout << "key = " << it->first << " value = " << it->second << std::endl << std::endl;
    std::cout << "number of pairs = " << query_map.size() << std::endl << std::endl;

    int     ret = 1;
    pid_t   childpid;
    int     status;

    childpid = fork();
    if (childpid < 0)
        ret = -1;
    if (childpid == 0)
    {
        int out = open("site/outfile.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (dup2(out, STDOUT_FILENO) < 0)
        {
            ret = -1;
            exit(EXIT_FAILURE);
        }
        ret = execve(cmd[0], cmd, env);
        close(out);
    } else
    {
        (void) waitpid(childpid, &status, 0);
        if (WIFEXITED(status))
            std::cout << "The cgi process exited with " << WEXITSTATUS(status) << std::endl << std::endl;
        _clean(cmd);
        _clean(env);
    }

    return ret == -1 ? Error_Internal_Server_Error : Error_OK;
}

void    WebServer::_clean(char** var)
{
    int i = 0;
    while (var[i])
    {
        delete[] var[i];
        i++;
    }
    delete[] var;
}

// We handle two types of CGI: PHP or an executable file like ./a.out from C.
char**  WebServer::_set_command(int client_id)
{
    std::string     filePath = _request_file_path(client_id);
    //char**          ret = (char**)malloc(sizeof(char*) * 4);
    char**          ret = new char*[4];

    if (filePath.find(".php") != std::string::npos)
    {
        std::string tmp0 = "/usr/local/bin/php-cgi";
        std::string tmp1 = "-f";
        std::string tmp2 = std::string("./" + filePath);
        ret[0] = new char[tmp0.size() + 1];
        ret[0] = strcpy(ret[0], const_cast<const char*>(tmp0.c_str()));
        ret[1] = new char[tmp1.size() + 1];
        ret[1] = strcpy(ret[1], const_cast<const char*>(tmp1.c_str()));
        ret[2] = new char[tmp2.size() + 1];
        ret[2] = strcpy(ret[2], const_cast<const char*>(tmp2.c_str()));
        ret[3] = 0;
    }
    else //(filePath.find(".a") != std::string::npos)
    {
        ret[0] = new char[filePath.size() + 1];
        ret[0] = strcpy(ret[0], const_cast<char*>(filePath.c_str()));
        ret[1] =0;
    }
    
    return ret;
}

// We assume there are no special characters in the QUERY_STRING
char**  WebServer::_split_query_string(std::string& whole_query, std::map<std::string, std::string>& split_query)
{
    std::istringstream  iss(whole_query);
    std::string         chunk;
    while (!iss.eof())
    {
        std::getline(iss, chunk, '&');
        size_t          seperator_pos = chunk.find('=');
        std::string     key = chunk.substr(0, seperator_pos);
        std::string     value = chunk.substr(seperator_pos + 1);
        split_query.insert(std::pair<std::string, std::string>(key, value));
    }

    for (std::map<std::string, std::string>::iterator it = split_query.begin(); it != split_query.end(); ++it)
        std::cout << "key = " << it->first << " value = " << it->second << std::endl << std::endl;
    std::cout << "number of pairs = " << split_query.size() << std::endl << std::endl;

    char**  ret = new char*[split_query.size() + 1];
    int     i = 0;
    for(std::map<std::string, std::string>::iterator it = split_query.begin(); it != split_query.end(); ++it, ++i)
    {
        ret[i] = new char[std::string(it->first + "=" + it->second).size() + 1];
        ret[i] = strcpy(ret[i], const_cast<const char*>(std::string(it->first + "=" + it->second).c_str()));
    }
    ret[i] = 0;

    return ret;
}

bool    WebServer::_autoindex_file(const std::string& directory_name, std::string& response_body)
{
    bool    ret = false;
    if (DIR* directory = opendir(directory_name.c_str()))
    {
        ret = true;
        response_body = "<html><head><title>Index of " + directory_name +
        "</title><link rel=\"icon\" href=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAIAAACQd1PeAAAADElEQVQI12P4//8/AAX+Av7czFnnAAAAAElFTkSuQmCC\"></head><body><h1>Index of "
        + directory_name + "</h1><hr>";
        while (struct dirent *entry = readdir(directory))
        {
            std::string file_name(entry->d_name);
            if (file_name != "." && file_name != "..")
                 response_body += "<a target=\"_blank\" href=" + file_name  + ">" + file_name + "</a><br>";
        }
        closedir(directory);
        response_body +=  "<hr></body></html>";
    }
    return ret;
}

// We assume the Content-Type to be: application/x-www-form-urlencoded, or text/plain, or fileload as multipart/form-data
// We only allow executable files to be located in /cgi-bin
int     WebServer::_POST(int client_id)
{
    client_headline&                    current_client_request_headline = client_group[client_id]->client_request_headline;
    std::map<std::string, std::string>  current_client_request_header = client_group[client_id]->client_request_header;
    std::string&                        current_client_request_body = client_group[client_id]->client_request_body;
    std::string&                        current_client_response_body = client_group[client_id]->server_response_body;

    int             ret = 1;
    std::string     path = current_client_request_headline.uri;

    if ((current_client_request_header.find("Content-Type")->second).substr(0, 19) == "multipart/form-data")
        ret = _fileUpload(client_id);
    else if (path.substr(0, 8) != "/cgi-bin")
        ret = Error_Internal_Server_Error;
    else
        ret = _cgi_POST(client_id, current_client_request_body);

    if (ret == Error_Created && path.substr(0, 8) == "/cgi-bin")
        read_file("site/outfile.txt", current_client_response_body);
    else 
        _serve_error_page(client_id, ret, current_client_response_body);

    return ret;
}

int     WebServer::_fileUpload(int client_id)
{
    std::string&    current_client_request_body = client_group[client_id]->client_request_body;
   
    size_t          start_pos = current_client_request_body.find("filename");
    current_client_request_body.erase(0, start_pos + 10);
    size_t          end_pos = current_client_request_body.find('"');
    std::string     fileName = current_client_request_body.substr(0, end_pos);
    size_t          seperator_pos = current_client_request_body.find("\r\n\r\n");
    current_client_request_body.erase(0, seperator_pos + 4);
    seperator_pos = current_client_request_body.find("------");
    current_client_request_body.erase(seperator_pos);
      
    if (!write_file("site/temp/" + fileName, current_client_request_body, current_client_request_body.size()))
        return Error_Internal_Server_Error;
    else
        return Error_Created;
}

int     WebServer::_cgi_POST(int client_id, const std::string& query)
{
    char**  cmd = _set_command(client_id);
    int     ret = 1;
    pid_t   childpid;
    int     status;

    std::map<std::string, std::string>      current_client_request_header = client_group[client_id]->client_request_header;
    int     body_size_limit = atoi((current_client_request_header.find("Content-Length")->second).c_str());
    if (!write_file("site/infile.txt", query, body_size_limit))
        return Error_Internal_Server_Error;

    childpid = fork();
    if (childpid < 0)
        ret = -1;
    if (childpid == 0)
    {
        int in = open("site/infile.txt", O_RDONLY);
        int out = open("site/outfile.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (dup2(in, STDIN_FILENO) < 0 || dup2(out, STDOUT_FILENO) < 0)
        {
            ret = -1;
            exit(EXIT_FAILURE);
        }
         std::cout << "this is where the problem is" << std::endl << std::endl;
        ret = execve(cmd[0], cmd, 0);
        close(in);
        close(out);
    } else
    {
        (void) waitpid(childpid, &status, 0);
        if (WIFEXITED(status))
            std::cout << "The cgi process exited with " << WEXITSTATUS(status) << std::endl << std::endl;
        _clean(cmd);
    }

    return ret == -1 ? Error_Internal_Server_Error : Error_Created;
}

int     WebServer::_DELETE(int client_id)
{
    client_headline&                    current_client_request_headline = client_group[client_id]->client_request_headline;

    int ret;
    if (current_client_request_headline.uri.substr(0, 5) != "/temp")
        ret = Error_Internal_Server_Error;
    else if (remove(_request_file_path(client_id).c_str()) == 0)
    {
        std::cout << "Path to remove the file: " << _request_file_path(client_id) << std::endl << std::endl;
        ret = Error_OK;
    }
        
    else
        ret = Error_No_Content;
    return ret;
}

void    WebServer::_set_server_response_headline(int client_id, int error_code)
{
    server_headline&        current_server_response_headline = client_group[client_id]->server_response_headline;

    current_server_response_headline.protocol = "HTTP/1.1";
    current_server_response_headline.code = error_code;
    current_server_response_headline.status = _errorcode_name(error_code);
}

bool WebServer::image_exists(std::string file) // to check if .jpg exists, if not 404
{
    std::ifstream infile(file.c_str());
    return infile.good();
}

bool WebServer::image_ext(const std::string& file)
{
    size_t pos = file.rfind('.');
    if (pos == std::string::npos)
        return false;

    std::string ext = file.substr(pos+1);

    if (ext == "jpg" || ext == "jpeg" || ext == "gif" || ext == "png")
        return true;

    return false;
}

void    WebServer::_set_server_response_header(int client_id, int error_code)
{
    std::map<std::string, std::string>& current_server_response_header = client_group[client_id]->server_response_header;
    std::string&                        current_server_response_body = client_group[client_id]->server_response_body;



    current_server_response_header.insert(std::pair<std::string, std::string>("Cache-Control", "no-cache, private"));
    current_server_response_header.insert(std::pair<std::string, std::string>("charset", "utf-8"));
    std::string fileName = _request_file_path(client_id);
    // std::size_t pos = fileName.find(".jpg");
    // if (pos != std::string::npos && file_exists(fileName))
    //     current_server_response_header.insert(std::pair<std::string, std::string>("Content-Type", "image/jpeg"));
    if (image_exists(fileName) && image_ext(fileName))
        current_server_response_header.insert(std::pair<std::string, std::string>("Content-Type", "image/jpeg"));
    else
        current_server_response_header.insert(std::pair<std::string, std::string>("Content-Type", "text/html"));
    current_server_response_header.insert(std::pair<std::string, std::string>("Content-Length", _error_code_to_string(current_server_response_body.size())));
    if (error_code == Error_Method_Not_Allowed)
        current_server_response_header.insert(std::pair<std::string, std::string>("Allow", "GET, POST, DELETE"));
    if (error_code == Error_Moved_Permanently)
        current_server_response_header.insert(std::pair<std::string, std::string>("Location", "/index.html"));
}

void    WebServer::_compose_response(std::string& server_response, int client_id)
{
    server_headline&                    current_server_response_headline = client_group[client_id]->server_response_headline;
    std::map<std::string, std::string>& current_server_response_header = client_group[client_id]->server_response_header;
    std::string&                        current_server_response_body = client_group[client_id]->server_response_body;

    server_response.append(current_server_response_headline.protocol + " ");
    server_response.append(_error_code_to_string(current_server_response_headline.code) + " ");
    server_response.append(current_server_response_headline.status  + "\r\n");
    for(std::map<std::string, std::string>::iterator it = current_server_response_header.begin(); it != current_server_response_header.end(); ++it)
        server_response.append(it->first + ": " + it->second + "\r\n");
    server_response.append("\r\n" + current_server_response_body);
}

