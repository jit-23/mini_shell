/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/15 09:56:57 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	execute(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2])
{
	ft_splitt(&pipex->cmd, cmd, ' ');
	get_cmds(pipex);
	if(pipex->cmd_path == NULL || !pipex->cmd)
	{
		free(fd);
		free_path(pipex->cmd);
		print_error(pipex);
	}
	execve(pipex->cmd_path, pipex->cmd, envp);
}

void	process_1(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2])
{
	close(pipex->fdout);
	manage_pipes(pipex->cmd_count, fd, pipex->i);
	dup2(pipex->fdin, 0);
	dup2(fd[pipex->i][1], 1);
	execute(pipex, cmd, envp, fd);
}

void	process_2(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2])
{
	close(pipex->fdin);
	close(pipex->fdout);
	manage_pipes(pipex->cmd_count, fd, pipex->i);
	dup2(fd[pipex->i - 1][0], 0);
	dup2(fd[pipex->i][1], 1);
	execute(pipex, cmd, envp, fd);
}

void	process_3(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2])
{
	close(pipex->fdin);
	manage_pipes(pipex->cmd_count, fd, pipex->i);
	dup2(fd[pipex->i - 1][0], 0);
	dup2(pipex->fdout, 1);
	execute(pipex, cmd, envp, fd);
}

void	processes(t_pipe *pipex, char **argv, char **envp, int cmd_count)
{
	int	(*fd)[2];

	pipex->i = 0;
	fd = (int (*)[2])malloc(sizeof(int [2]) * (cmd_count - 1));
	create_pipe(pipex, cmd_count - 1, fd);
	pipex->pid[0] = fork_creation(fd, pipex);
	if (pipex->pid[0] == 0)
		process_1(pipex, argv[2], envp, fd);
	waitpid(pipex->pid[0], NULL, WNOHANG);
	pipex->i = 1;
	while ((cmd_count - 1) > pipex->i)
	{
		pipex->pid[pipex->i] = fork_creation(fd, pipex);
		if (pipex->pid[pipex->i] == 0)
			process_2(pipex, argv[pipex->i + 2], envp, fd);
		waitpid(pipex->pid[pipex->i], NULL, WNOHANG);
		pipex->i++;
	}
	pipex->pid[pipex->i] = fork_creation(fd, pipex);
	if (pipex->pid[pipex->i] == 0)
		process_3(pipex, argv[pipex->i + 2], envp, fd);
	waitpid(-1, NULL, WNOHANG);
	free(fd);
}
