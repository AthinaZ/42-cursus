/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi & azouzoul <marvin@42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:34:55 by fminardi &        #+#    #+#             */
/*   Updated: 2021/07/10 13:34:56 by fminardi &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_home_end(int c, t_shell *g_shell)
{
	if (c == 72)
	{
		while (g_shell->current->index > 0)
		{
			write(1, "\b", 1);
			g_shell->current->index--;
		}
	}
	else
	{
		while (g_shell->current->index
			< (int)ft_strlen(g_shell->current->row))
		{
			write(1, "\033[C", 3);
			g_shell->current->index++;
		}
	}
}
