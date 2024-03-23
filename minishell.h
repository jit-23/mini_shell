/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:16:21 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/04 20:45:10 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "includes/pipex/pipex.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

typedef struct s_history
{
	int i;
	char *cmd_str;
	struct s_history *prev;
	struct s_history *next;
}t_history;

void	shell_history(t_history *cmd_hist, char *command);


#endif
