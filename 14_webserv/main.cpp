/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxu <mxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:36:59 by mxu               #+#    #+#             */
/*   Updated: 2022/04/21 12:56:23 by mxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServer.hpp"

int main(int ac, char** av)
//int main()
{
    WebServer   webServ;
    try
    {
        // Parse Server Configuration file
        webServ.parse_config(ac, av);
        //webServ.simple_config("127.0.0.1", 8080);
        // Opening sockets for listening
        webServ.init();
        // Server-client communication
        webServ.run();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
