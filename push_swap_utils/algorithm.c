/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:16:02 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/26 17:05:50 by pmelo-ca         ###   ########.fr       */
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
	if ((*stack_a)->top->index == 1)
	{
		if ((*stack_a)->top->next->index == 2)
		{
			rotate(stack_a);
			swap(stack_a);
		}
		else
			reverse_rotate(stack_a);
	}
	else if ((*stack_a)->top->index == 2)
	{
		if ((*stack_a)->top->next->index == 3)
		{
			reverse_rotate(stack_a);
			swap(stack_a);
		}
		else
			rotate(stack_a);
	}
	else
		swap(stack_a);
}

void	sort_greater_than_3(t_stack **stack_a, t_stack **stack_b)
{

}
