/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:46:24 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/23 18:03:33 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_to_history(t_history **history, char *cmd)
{
	t_history *head;
	//t_history *last;

	head = (*history);
	while(head->next != NULL)
		head = head->next;
	//last = head;
	head->next = ft_lstnew(cmd);
	//head->next->prev = last;
	head->next->next = 0;
}

void	init_mini(t_mini *mini)
{
	mini = (t_mini *)malloc(sizeof(t_mini));
	mini->history = (t_history *)malloc(sizeof(t_history));
	
	ft_memset(&mini->history, 0, sizeof(mini->history));
}


int main()
{
	t_mini mini;

	init_mini(&mini);
	int i = 1;
	while(i < 4)
	{
		mini.history->input = readline("$>");
		if (!mini.history->input)
			ft_putstr_fd("\n", 1);
		else if (mini.history->input)
			add_to_history(&mini.history, mini.history->input);
		i++;
	}
	printf("a -%s\n",mini.history->input);
	printf("a -%s\n",mini.history->next->input);
	printf("a -%s\n",mini.history->next->next->input);
	//while(mini.history)
	//{
	//	printf("cmd - %s\n", mini.history->input);
	//	mini.history = mini.history->next;
	//}
return 0;
}

//int main()
//{
//	t_mini mini;
//
//	init_mini(&mini);
//	t_history *a;
//	int i = 1;
//	while(i < 4)
//	{
//		mini.history->input = readline("$>");
//		if (!mini.history->input)
//			ft_putstr_fd("\n", 1);
//		else if (mini.history->input)
//			add_to_history(&mini.history, mini.history->input);
//		i++;
//	}
//	a = ft_lstlast(mini.history);
//	printf("%s\n", a->input);
//	while(a->prev == 0)
//	{
//		printf("cmd - %s\n", a->input);
//		a = a->prev;
//	}
//	return 0;
//}
