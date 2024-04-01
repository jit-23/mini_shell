/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_cmd_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:29:58 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/04/01 20:18:39 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void single_char(char *cmd_line, t_mini *bsh) // specify the errors of the exact commands
{
	if (ft_strlen(cmd_line) == 1)
	{
		if (cmd_line[0] == ';' || cmd_line[0] == '|')
		{
			printf("ERROR ( : | ) \n");// sintax error msg		
		}
		else if (cmd_line[0] == 'w') // only good outcome
			execute_1_char_cmd(cmd_line, bsh);
		else
		{
			printf("%s: command not found\n", bsh->cmd_line);
			//printf(command not found);
		}  
	}
}

void	check_cmd_content(char *cmd_line, t_mini *bsh)
{
	if (ft_find_chrs(cmd_line,"\t "))
	{
		printf("parsing\n");
		//parsing(cmd_line, bsh);
	}
	else
	{
		execute_simple_cmd(cmd_line, bsh);
	}
}


/* first function to touch the cmd  - (analise_cmd) */
void	analise_cmd(char *cmd_line ,t_mini *bsh)
{
	//int i;
	int size;

	size = ft_strlen(cmd_line);
	//i = 0;
	if (size == 1)
		single_char(cmd_line, bsh);
	else
	{
		check_cmd_content(cmd_line, bsh);
	}
}