/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi & azouzoul <marvin@42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:36:39 by fminardi &        #+#    #+#             */
/*   Updated: 2021/07/10 13:36:40 by fminardi &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	*test;

	test = malloc(sizeof(char) * 4096);
	test = getcwd(test, 4096);
	ft_printf_fd(1, "%s\n", test);
	free(test);
}
