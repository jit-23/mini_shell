/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:16:21 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/04 02:19:27 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/history.h>
#include <readline/readline.h>
#include "includes/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

typedef struct s_builtin
{
	char **tokens;
	
}t_btin;

typedef struct s_executable
{
	char **tokens;
	
}t_exec;


typedef union token_type
{
		t_btin builtin;
		t_exec executable;
}token_type;

// typedef struct s_parse
typedef struct s_parse
{
	token_type type;
	char **cmd_tokens;
		
	
}t_parse;

typedef struct s_mini
{
	int n_pipes;
	int n_cmds;
	
	char **env;
	char *path;
	char *cmd_line;
	char *prompt;
	t_parse *full_cmd;	
}t_mini;

void 	get_prompt(t_mini *bsh);
void	analise_cmd(char *cmd_line ,t_mini *bsh);
void	single_char(char *cmd_line, t_mini *bsh); // specify the errors of the exact commands
void	check_cmd_content(char *cmd_line, t_mini *bsh);
int		only_spaces(char *cmd_line);

/* exec_single_cmd*/
void	execute_1_char_cmd(char *cmd, t_mini *bsh);
char 	*find_path(char* cmd,char **env);
char	**env_array(char *path, char *cmd);
void	execute_simple_cmd(char *cmd_line, t_mini *bsh);
void	clean_mem(char **path_array, char **buff, char *cmd);

/* parsing */

void	init_parse_struct(char **cmds, t_mini *bsh);
void	parsing(char *cmd_line, t_mini *bsh);
char	*get_access(char *cmd_path, char **path_exec);


void	design_tokens(char *cmd, t_mini *bsh, int i);
int		is_builtin(char *cmd);
void 	init_path(char **env, t_mini *bsh);

int is_builtin(char *cmd);
int is_exec(char *cmd, t_mini *bsh);
void design_tokens(char *cmd, t_mini *bsh, int i);

/* typedef struct s_parse
{
	char **cmd_tokens;
		
	int executable;
	int file_related;
	int builtin;
}t_parse; */


#endif
