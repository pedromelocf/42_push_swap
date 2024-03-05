/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:55 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/05 14:48:42 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		exit_status(int error, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	exit(error);
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree,
			int *arr_int)
{
	short int	size;
	stack_a = NULL;
	stack_b = NULL;

	size = 1;
	while(size < (*btree)->index)
	{
		(*stack_a)->curr = malloc(sizeof(t_node));
		(*stack_a)->curr->index = search_index(*btree, &arr_int);
		(*stack_a)->curr->pos_a = size;
		(*stack_a)->curr->pos_b = 0;
		(*stack_a)->curr->target_pos = 0;
		(*stack_a)->curr->cost_move = 0;
		(*stack_a)->prev = NULL;
		(*stack_a)->next = NULL;
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
