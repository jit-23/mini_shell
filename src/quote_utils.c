/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:10:47 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/06/01 17:31:57 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"


char *get_normal_string(char *cmdl,int *i, t_shell *sh, int c)
{
	char *s;
	char *t;

    intptr_t j = (intptr_t)i;
	s = malloc(sizeof(char) * 1);
	t = malloc(sizeof(char) * 2);
	s[0] = '\0';
	t[1] = '\0';
	while(cmdl[j] && cmdl[j] != c)
	{
		t[0] = cmdl[j];
		s = ft_strjoin(s, t);
		j++;
	}
	free(t);
    i = (int *)j;
	return (s);
}

char *get_pre_expand(char *cmdl, int *i, t_shell *sh)
{
	char *s;
	char *t;
    intptr_t j;

    j = (intptr_t )i;
	s = malloc(sizeof(char) * 1);
	t = malloc(sizeof(char) * 2);
	s[0] = '\0';
	t[1] = '\0';
	while(cmdl[j] && cmdl[j] != '\'' && cmdl[j] != '$')
	{
		t[0] = cmdl[j];
		s = ft_strjoin(s, t);
		j++;
	}
    i = (int *)j;
	free(t);
	return (s);
}

char *get_post_expand(char *cmdl, int *i, t_shell *sh)
{
	char *s;
	char *t;
    intptr_t j;

    j = (intptr_t )i;
	s = malloc(sizeof(char) * 1);
	t = malloc(sizeof(char) * 2);
	s[0] = '\0';
	t[1] = '\0';
	while(cmdl[j] && cmdl[j] != '\'')
	{
		t[0] = cmdl[j];
		s = ft_strjoin(s, t);
		j++;
	}
	free(t);
    i = (int *)j;
	return (s);
}

int is_in_env_list(char *possible_env_var, t_shell *sh)
{
	t_env *head;

	head = sh->ev;
	while(head)
	{
		if (ft_strncmp(possible_env_var, head->env_name, ft_strlen(possible_env_var)) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}
int is_dollar_sign_valid(char *cmdl, int i, t_shell *sh)
{
	char s[1];

	char *q;
	q = malloc(sizeof(char) * 1);
	q[0] = '\0';
	while(cmdl[i] && cmdl[i] != '\'')
	{
		if (cmdl[i]  == '$')
		{
			while(cmdl[i] && !is_space(cmdl[i]))
			{
				s[0] = cmdl[i];
				q = ft_strjoin(q,s);
			}
		}
		i++;
	}
	if (is_in_env_list(q, sh))
		return (1);
	return (0);
}

char *get_env_expanded(char *cmdl, int *i, t_shell *sh)
{
	char s[1];

	char *q;
	q = malloc(sizeof(char) * 1);
	q[0] = '\0';
	while(cmdl[*i] && cmdl[*i] != '\'' && !is_space(cmdl[*i]))
	{
		s[0] = cmdl[*i];
		q = ft_strjoin(q,s);
		i++;
	}
	return (q);
}

char *get_expanded_string(char *cmdl,int *i, t_shell *sh)
{
    int h;

    h = *i;
	char *token;
	if (!is_dollar_sign_valid(cmdl,h, sh)) // there is a possible env_var
		return (get_normal_string(cmdl, i, sh, '\''));
	token = get_pre_expand(cmdl, i, sh);
	token = ft_strjoin(token, get_env_expanded(cmdl, i, sh)); // will concatenate the actual env var, already expanded.
	token = ft_strjoin(token, get_post_expand(cmdl, i, sh)); // will concatenate the rest of the string if there is anything to add
	return (token);
}


int	get_SQ_token(char *cmdl,int i, t_shell *sh, t_placing place)
{
	int sq_count_start;
	int sq_count_end;
	char *token;

	sq_count_end = 0;	
	sq_count_start = 0;
	while(cmdl[i] && cmdl[i] == '\'')
	{
		sq_count_start++;
		i++;
	}
	if (sq_count_start % 2 == 1) // dont need to expand
		token = get_normal_string(cmdl, &i, sh, '\'');
	else if (sq_count_start % 2 == 0) // need to expand
		token = get_expanded_string(cmdl, &i, sh);
	while(cmdl[i] && cmdl[i] == '\'')
	{
		sq_count_start++;
		i++;
	}
	if ((sq_count_end % 2) != (sq_count_start % 2))
		printf("IRREGULAR QUOTE NBR\n"); // TODO exit/ clean all
	add_to_list(sh->token_list, token,WORD,DEFAULT);
	return (i);
}

int	get_DQ_token(char *cmdl,int i, t_shell *sh, t_placing place)
{
	int sq_count_start;
	int sq_count_end;
	char *token;

	while(cmdl[i] && cmdl[i] == '\"')
	{
		sq_count_start++;
		i++;
	}
	token = get_normal_string(cmdl, &i, sh, '\"');
	while(cmdl[i] && cmdl[i] == '\"')
	{
		sq_count_end++;
		i++;
	}
	if ((sq_count_end % 2) != (sq_count_start % 2))
		printf("IRREGULAR QUOTE NBR\n");
	add_to_list(sh->token_list, token,WORD,DEFAULT);
	return (i);
}