/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:16:02 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/26 18:51:12 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->amount_of_numbers == 2)
		swap(stack_a);
	else if ((*stack_a)->amount_of_numbers == 3)
		sort_3(stack_a);
	else
		sort_greater_than_3(stack_a, stack_b);
}

void sort_3(t_stack **stack_a)
{
	if ((*stack_a)->top->index < (*stack_a)->top->prev->index)
	{
		if((*stack_a)->top->prev->index < (*stack_a)->top->prev->prev->index)
		{
			rotate(stack_a);
			swap(stack_a);
		}
		else
			reverse_rotate(stack_a);
	}
	else
	{
		if ((*stack_a)->top->prev->index < (*stack_a)->top->prev->prev->index)
		{
			if ((*stack_a)->top->index < (*stack_a)->top->prev->prev->index)
				rotate(stack_a);
			else
				swap(stack_a);
		}
		else
		{
			reverse_rotate(stack_a);
			swap(stack_a);
		}
	}
}

void	sort_greater_than_3(t_stack **stack_a, t_stack **stack_b)
{

}
