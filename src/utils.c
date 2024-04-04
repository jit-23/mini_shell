/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:46:18 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/04 02:15:49 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	only_spaces(char *cmd_line)
{
	char *s;
	int i;

	s = cmd_line;
	i = 0;
	while(s[i])
	{
		if (s[i] != 32)
			return (1);
		i++;	
	}
	return (0);
}

void init_path(char **env, t_mini *bsh)
{
	int i;

	i = -1;
	bsh->path = NULL;
	while (env[++i])
	{
		bsh->path = ft_strnstr(env[i], "PATH=", 5);
		if (bsh->path)
			break ;
		else
			continue ;
	}
}