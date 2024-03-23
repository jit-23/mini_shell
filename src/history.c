
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:06 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/03 18:39:21 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_history	*ft_newlst(char *str)
{
	t_history	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->cmd_str = str;
	new_node->next = NULL;
	return (new_node);
}

void	shell_history(t_history *cmd_hist, char *command)
{
	if (!cmd_hist)
	{
		cmd_hist = (t_history *)malloc(sizeof(t_history));
		if (!cmd_hist)
			exit(1);
	}
	if (!cmd_hist->cmd_str) // first cmd of the program
	{
		cmd_hist->prev = 0;
		cmd_hist->i = 1;
		cmd_hist->cmd_str = command;
		cmd_hist->next = 0;
	}
	else
	{
		cmd_hist->next = ft_newlst(command);
		cmd_hist->next->prev = cmd_hist;
		cmd_hist->next->i = (cmd_hist->i + 1);
		cmd_hist = cmd_hist->next;
	}
}
