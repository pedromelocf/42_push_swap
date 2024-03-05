/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:55 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/05 16:20:52 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree,
			int *arr_int)
{
	short int	size;
	short int	lenght;
	stack_a = NULL;
	stack_b = NULL;

	size = 1;
	lenght = (*btree)->index;
	stack_a = malloc(sizeof(t_stack));
	while(size <= lenght)
	{
		(*stack_a)->curr = malloc(sizeof(t_node));
		(*stack_a)->curr->index = search_index(*btree, &arr_int);
		(*stack_a)->curr->pos_a = size;
		if(size == 1)
			(*stack_a) = (*stack_a)->next;
		else
		{
			(*stack_a)->prev = (*stack_a)->curr;
			(*stack_a) = (*stack_a)->next;
		}
		size++;
	}
	if (!stack_a)
		exit_status(1, NULL);
	if (!stack_b)
		exit_status(1, NULL);
	clean_tree(*btree);
	ft_clean_arr_int(arr_int);
	return;
}

int		exit_status(int error, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	exit(error);
}
