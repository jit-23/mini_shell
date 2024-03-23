/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:46:18 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/23 17:55:30 by fde-jesu         ###   ########.fr       */
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
