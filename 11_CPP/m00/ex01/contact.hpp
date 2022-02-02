/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:06 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/22 16:53:11 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	public:

	Contact(void);
	~Contact(void);

	void get_info(int i);
	void print_header();
	void print_table();
	void print_contact();

	private:

	int index;
	std::string field_info[5];
};

#endif

