/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

# define	GRN			"\e[0;32m"
# define	OFF			"\033[0m"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &copy);
		FragTrap(std::string const &name);
		~FragTrap();
		FragTrap &operator=(FragTrap const &rhs);
		void attack(const std::string &target);
		void highFivesGuys();
	// protected:
	// 	unsigned int hitPoints;
	// 	unsigned int attackDamage;
};

#endif
