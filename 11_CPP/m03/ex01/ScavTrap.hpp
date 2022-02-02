/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:34:49 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:51 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define	MAG			"\e[0;35m"
# define 	YEL			"\e[0;33m"
# define	OFF			"\033[0m"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &copy);
		ScavTrap(std::string const &name);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &rhs);
		void attack(std::string const &target);
		void guardGate();
};

#endif
