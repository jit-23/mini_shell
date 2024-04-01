/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:55:36 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/01 03:22:31 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_the_access(char *cmd_path, char **path_exec)
{
	int	i;

	i = 0;
	if (!cmd_path)
		cmd_path = "";
	while (path_exec[i])
	{
		if (access(path_exec[i], X_OK) == 0)
		{
			cmd_path = ft_strdup(path_exec[i]);
			return (cmd_path);
		}
		i++;
	}
	return (0);
}

char 	*find_path(char* cmd, char **env)
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
	cmd = get_the_access(cmd,ev_plus_cmds);
	return (cmd);
}

void	execute_1_char_cmd(char *cmd, t_mini *bsh)
{
	cmd = find_path(cmd, bsh->env);
	int pid;
	char *cmds[] = {cmd, NULL};
	pid = fork();
	if (pid == 0)
		execve(cmd, cmds, NULL);
	waitpid(-1,0,0);
}

void	execute_simple_cmd(char *cmd, t_mini *bsh)
{
	cmd = find_path(cmd, bsh->env);
	int pid;
	char *cmds[] = {cmd, NULL};
	pid = fork();
	if (pid == 0)
		execve(cmd, cmds, NULL);
	waitpid(-1,0,0);
}

static void	clean_mem(char **path_array, char **buff, char *cmd)
{
	int	i;

	i = -1;
	if (buff)
	{
		while (buff[++i])
			free(buff[i]);
		free(buff);
	}
	i = -1;
	if (path_array)
	{
		while (path_array[++i])
			free(path_array[i]);
		free(path_array);
	}
	if (cmd)
		free(cmd);
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

