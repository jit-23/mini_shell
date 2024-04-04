/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:19:13 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/04 02:25:58 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_builtin(char *cmd)
{
	int i;
	char **words;

	words = ft_split(cmd, ' ');
	i = -1;
	while(words[++i])
	{
		if (!(strncmp(words[i], "cd", sizeof("cd"))))
			break ;
		if (!(strncmp(words[i], "echo", sizeof("echo"))))
			break ;
		if (!(strncmp(words[i], "pwd", sizeof("pwd"))))
			break ;
		if (!(strncmp(words[i], "export", sizeof("export"))))
			break ;
		if (!(strncmp(words[i], "unset", sizeof("unset"))))
			break ;
		if (!(strncmp(words[i], "exit", sizeof("exit"))))
			break ;
		if (!(strncmp(words[i], "env", sizeof("env"))))
			break ;
	}
	if (!words[i])
		return (0); // make free function to world side a side to the return ();
	return (1);
}

int is_exec(char *cmd, t_mini *bsh)
{
	char **executable;
	init_path(bsh->env, bsh);
	executable = env_array(bsh->path, cmd);
	//int i = -1;
	// while(executable[++i])
	// 	printf("%s\n", executable[i]);
	if (get_access(cmd, executable))
		return (1);
	return (0);
}

void design_tokens(char *cmd, t_mini *bsh, int i)
{
	printf("cmd - %s\n", cmd);
	if (is_builtin(cmd)) // procura na string a palavra chave para saber se e builtin ou n, caso fo, so ai e que fzs split para os tokens
	{
		bsh->full_cmd[i].type.builtin.tokens = (char **)malloc(sizeof(char *) * ft_count(cmd, ' ') + 1);
		bsh->full_cmd[i].type.builtin.tokens = ft_split(cmd, ' ');
		printf("is b\n");
		return ;
	}
	if (is_exec(cmd, bsh))
	{
		bsh->full_cmd[i].type.executable.tokens = (char **)malloc(sizeof(char *) * ft_count(cmd, ' ') + 1);
		bsh->full_cmd[i].type.executable.tokens = ft_split(cmd, ' ');
		printf("is exec\n");
		return ;
	}
	else
	{
		printf("idk\n");
	}
}
// the array of struct full_cmds is filled with the cmds separated by the pies.
	// so each full_cmd[i] will have a array (defined by cmd_token) of the tokens that will represent the respective cmd and its flags.
	/* IT CANNOT HANDLE FILES OR REDIRECTIONS '<''>' NEITHER HEREDOCS*/  
//	define_token_type(bsh);
void init_parse_struct(char **cmds, t_mini *bsh)
{
	int i;

	i = -1;
	bsh->full_cmd = (t_parse *)malloc(sizeof(t_parse) * bsh->n_cmds);
	while(cmds[++i])
		design_tokens(cmds[i], bsh, i);
		
	printf("END TO IT\n");
}

/*
	 while(cmds[i])
	{
		bsh->full_cmd[i].cmd_tokens  = (char **)malloc(sizeof(char *) * ft_count(cmds[i], ' ') + 1);
		bsh->full_cmd[i].cmd_tokens = ft_split(cmds[i], ' ');
		i++;
	} */

void	parsing(char *cmd_line, t_mini *bsh)
{
	char **sep_cmds;
	bsh->n_pipes = ft_count(cmd_line, '|');
	bsh->n_cmds = bsh->n_pipes + 1;
	sep_cmds = ft_split(cmd_line, '|');
	init_parse_struct(sep_cmds, bsh); 
	
}

//void	define_token_type(bsh)
//{
//	
//}