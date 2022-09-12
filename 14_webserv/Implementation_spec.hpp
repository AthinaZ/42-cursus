/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Implementation_spec.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42roma.it>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:17:44 by mxu               #+#    #+#             */
/*   Updated: 2022/06/17 22:02:38 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLEMENTATION_SPEC_HPP_
#define IMPLEMENTATION_SPEC_HPP_

#include <string>
#include <map>
#include <vector>
#include <exception>

#define default_config_file "./site/default_localhost.conf"

enum    Server_Conf
{
    server_server_name,
    server_listen,
    server_root,
    server_index,
    server_autoindex,
    server_location,
    server_error_page,
    //server_allowed_methods,
    //server_body_size,
    //server_cgi,
    //server_redirect,
    //server_upload_pass
};

enum    HTTP_METHODS
{
    HTTP_GET,
    HTTP_POST,
    HTTP_DELETE
};

enum    HTTP_ERRORCODE
{
    Error_OK = 200,
    Error_Created = 201,
    Error_No_Content = 204,
    Error_Moved_Permanently = 301,
    Error_Forbidden = 403,
    Error_Not_Found = 404,
    Error_Method_Not_Allowed = 405,
    Error_Internal_Server_Error = 500
};

enum    Request_Headers
{
    Request_Host,
    Request_Connection,
    Request_Cache_Control,
    //User-Agent,
    Request_Accept,
    //Accept-Encoding,
    //Accept-Language
};

enum    Response_Headers
{
    //Cache-Control,
    Response_Content_Type,
    Response_Content_length
};

#endif
