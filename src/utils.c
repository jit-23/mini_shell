/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:46:18 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/31 02:33:58 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_history	*ft_lstnew(char *content)
{
	t_history	*new_node;

	new_node = malloc(sizeof(t_history));
	if (!new_node)
		return (0);
	new_node->input = content;
	new_node->next = NULL;
	return (new_node);
}

t_history	*ft_lstlast(t_history *lst)
{
	t_history	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

int	only_spaces(char *cmd_line)
{
	char *s;
	int i;

	s = cmd_line;
	i = 0;
	while(s[i])
	{
		if (s[i] != 32)
			return (1);
		i++;	
	}
	return (0);
}