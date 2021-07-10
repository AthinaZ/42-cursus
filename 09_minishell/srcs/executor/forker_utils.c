/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi & azouzoul <marvin@42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:35:54 by fminardi &        #+#    #+#             */
/*   Updated: 2021/07/10 13:35:55 by fminardi &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	restore_fd(t_forker *forker, t_cmd *cmd)
{
	if (cmd->file_out != 1)
		close(cmd->file_out);
	if (cmd->file_in != 0)
		close(cmd->file_in);
	dup2(forker->saved_stdout, STDOUT_FILENO);
	dup2(forker->saved_stdin, STDIN_FILENO);
	close(forker->saved_stdout);
	close(forker->saved_stdin);
}
