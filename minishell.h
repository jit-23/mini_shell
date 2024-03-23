/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:16:21 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/23 17:48:20 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/history.h>
#include <readline/readline.h>
#include "includes/pipex/pipex.h"
#include "includes/pipex/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

typedef struct s_history
{
	int i;
	char *input;
	struct s_history *prev;
	struct s_history *next;
}t_history;

typedef struct s_mini
{
	struct s_history *history;
}t_mini;

void 	init_mini(t_mini *mini);
void	add_to_history(t_history **history, char *cmd);

t_history	*ft_lstnew(char *content);
t_history	*ft_lstlast(t_history *lst);


#endif
