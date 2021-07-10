/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi & azouzoul <marvin@42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:36:26 by fminardi &        #+#    #+#             */
/*   Updated: 2021/07/10 13:36:32 by fminardi &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_shell *g_shell)
{
	if (!ft_strcmp(g_shell->prompt, "peppere> "))
		ctrl_c();
	else
	{
		ft_free_env(g_shell->env);
		free_old(g_shell->current);
		free_history(g_shell->current);
		printf("exit\n");
		exit(0);
	}
}
