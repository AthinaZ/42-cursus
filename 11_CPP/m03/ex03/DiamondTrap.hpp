/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

# define	CYN 		"\e[0;36m"
# define 	YEL			"\e[0;33m"
# define	OFF			"\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap // order matters!!
{
	public:
		DiamondTrap();
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap(std::string const &name);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &rhs);
		void attack(std::string const &target);
		void whoAmI();
	private:
		std::string name;
};

#endif
