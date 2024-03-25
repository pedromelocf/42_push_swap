/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:54:29 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/25 20:12:44 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_node *temp_node;

	temp_node = malloc(sizeof(t_btree));
	while (stack_a)
	{
		temp_node = (*stack_a)->top->next;
		free((*stack_a)->top);
	}
	free(stack_a);
	free(stack_b);
}