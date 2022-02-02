/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 15:12:40 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_hpp
#define Brain_hpp

#include <iostream>

# define	BLUE		"\033[0;34m"
# define 	YEL			"\e[0;33m"
# define	OFF			"\033[0m"

class Brain
{
	public:
		std::string ideas[100];
		Brain();
		Brain(const Brain &brain);
		Brain &operator = (const Brain &Brain);
		void	setIdea(const std::string &idea);
		std::string getIdea() const;
		~Brain();
};

#endif 
