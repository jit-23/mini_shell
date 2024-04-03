/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:19:13 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/03 04:32:41 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void init_parse_struct(char **cmds, t_mini *bsh)
{
	int i;

	i = 0;
	bsh->full_cmd = (t_parse *)malloc(sizeof(t_parse) * bsh->n_cmds);
	while(cmds[i])
	{
		bsh->full_cmd[i].cmd_tokens  = (char **)malloc(sizeof(char *) * ft_count(cmds[i], ' ') + 1);
		bsh->full_cmd[i].cmd_tokens = ft_split(cmds[i], ' ');
		i++;
	}
	int i;

	
	printf("END TO IT\n");
}

void	parsing(char *cmd_line, t_mini *bsh)
{
	char **sep_cmds;
	bsh->n_pipes = ft_count(cmd_line, '|');
	bsh->n_cmds = bsh->n_pipes + 1;
	sep_cmds = ft_split(cmd_line, '|');
	init_parse_struct(sep_cmds, bsh); // the array of struct full_cmds is filled with the cmds separated by the pies.
	// so each full_cmd[i] will have a array (defined by cmd_token) of the tokens that will represent the respective cmd and its flags.
	/* IT CANNOT HANDLE FILES OR REDIRECTIONS '<''>' NEITHER HEREDOCS*/  
	
	
}
