/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:46:24 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/01 20:43:07 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void get_prompt(t_mini *bsh)
{
	char *directory;

	directory = NULL;
	directory = getcwd(directory, 1000);
	bsh->prompt = ft_strjoin(directory, "$ ");
	bsh->cmd_line = readline(bsh->prompt);
	if (bsh->cmd_line && only_spaces(bsh->cmd_line))
		add_history(bsh->cmd_line);
	free(directory);
}

static void	built_in(t_mini *bsh, char *cmd_line)
{
	
	char *cmds[] = {cmd_line, NULL};
	printf("aki SIM\n");
	
	// cmds = (char **)malloc(sizeof(char *) * 2);
	// cmds[0] = (char*)malloc(sizeof(char) * sizeof(cmd_line) + 1);
	// cmds[1] = NULL;
	// cmds[0] = ft_memcpy
	//execve(cmd_line, cmds, bsh->env);
	printf("NOOO\n");
}




int main(int ac, char **av, char **env)
{
	t_mini bsh;

	if (ac != 1)
		return (1);
	ft_memset(&bsh,  0, sizeof(t_mini));
	bsh.env = env;
	while(1)
	{
		get_prompt(&bsh);
		if (bsh.cmd_line)
		{
			if(!(ft_strncmp(bsh.cmd_line, "env", sizeof("env"))))
				built_in(&bsh, bsh.cmd_line);
			else
				analise_cmd(bsh.cmd_line, &bsh);
		}
	}
	return 0;
}

