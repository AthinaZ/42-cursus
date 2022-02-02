/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:54:05 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/22 16:54:07 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class Phonebook
{
	private:
	Contact book[8];
	int count;

	public:

	Phonebook();
	~Phonebook();

	void add(int i);
	void search(void);

};

#endif

