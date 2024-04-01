/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:55:36 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/31 03:19:11 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char 	*find_path(char* cmd,char **env)
{
	char	*path;
	int		i;
	char **ev_plus_cmds;
	char *cmd_path;
	i = -1;
	while (env[++i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
			break ;
		else
			continue ;
	}
	path = &path[5];
	ev_plus_cmds = env_array(path, cmd);
	cmd = get_access(cmd,ev_plus_cmds);
	return (cmd);
}

void	execute_1_char_cmd(char *cmd, char **env)
{
	
	cmd = find_path(cmd, env);
	int pid;
	pid = fork();
}

char	**env_array(char *path, char *cmd)
{
	int		i;
	char	**buff;
	char	**path_array;

	i = -1;
	buff = ft_split(path, ':');
	if (!buff)
	{
		clean_mem(0, buff, cmd);
		exit(1);
	}
	cmd = ft_strjoin("/", cmd);
	path_array = (char **)malloc(sizeof(char *) * (ft_count(path, ':') + 1));
	if (!path_array)
	{
		clean_mem(path_array, buff, cmd);
		exit(1);
	}
	while (buff[++i])
		path_array[i] = ft_strjoin(buff[i], cmd);
	path_array[i] = 0;
	clean_mem(0, buff, cmd);
	return (path_array);
}
