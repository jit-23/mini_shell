/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/15 09:53:44 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

pid_t fork_creation(int (*fd)[2], t_pipe *pipex)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		free(fd);
		print_error(pipex);
	}
	return (pid);
}

void	create_descriptors(t_pipe *pipex, char **argv, char **envp, int ac)
{
	pipex->cmd_count = ac -3;
	if (envp == NULL || argv == NULL || ac < 5)
		exit (1);
	pipex->fdin = open(argv[1], O_RDWR);
	if (pipex->fdin <= 0)
		exit (2);
	pipex->fdout = open(argv[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->fdout <= 0)
	{
		close(pipex->fdin);
		exit (2);
	}
	pipex->pid = malloc((ac - 2) * sizeof(int));
	if (pipex->pid == NULL)
	{
		close(pipex->fdin);
		close(pipex->fdout);
		exit(3);
	}
}

int	main(int ac, char **argv, char **envp)
{
	t_pipe	pipex;

	create_descriptors(&pipex, argv, envp, ac);
	get_path(&pipex, envp);
	processes(&pipex, argv, envp, ac -3);
	wait(NULL);
	print_error(&pipex);
	return (0);
}
