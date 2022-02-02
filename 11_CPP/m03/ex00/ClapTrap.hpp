/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:32:50 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:32:52 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

# define	BLUE		"\033[0;34m"
# define 	YEL			"\e[0;33m"
# define	OFF			"\033[0m"


class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &copy);
		ClapTrap(std::string const &name);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &rhs);
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif
