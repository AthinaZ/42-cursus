/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:04:31 by azouzoul          #+#    #+#             */
/*   Updated: 2021/01/22 15:44:20 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != (unsigned char)c) && (*s != '\0'))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
