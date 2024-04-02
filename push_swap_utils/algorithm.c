/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:16:02 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/01 23:45:42 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->amount_of_numbers == 2)
		swap(stack_a, "a");
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
			rotate(stack_a, "a");
			swap(stack_a, "a");
		}
		else
			reverse_rotate(stack_a, "a");
	}
	else
	{
		if ((*stack_a)->top->prev->index < (*stack_a)->top->prev->prev->index)
		{
			if ((*stack_a)->top->index < (*stack_a)->top->prev->prev->index)
				rotate(stack_a, "a");
			else
				swap(stack_a, "a");
		}
		else
		{
			reverse_rotate(stack_a, "a");
			swap(stack_a, "a");
		}
	}
}

void	sort_greater_than_3(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	push_b_until_three(stack_a, stack_b);
	sort_3(stack_a);
	while (i < (*stack_a)->amount_of_numbers - 3)
	{
		update_position(*stack_a, *stack_b);
		calc_target_pos(*stack_a, *stack_b);
		get_move_cost(*stack_a, *stack_b);
		make_cheapest(stack_a, stack_b);
		i++;
	}
	validate_rotates(stack_a);
}

void	push_b_until_three (t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	p;
	int	x;

	i = 0;
	p = (*stack_a)->amount_of_numbers / 4;
	x = 0;
	while(i < (*stack_a)->amount_of_numbers - 3)
	{
		p *= 2;
		x -= i;
		while (x < (*stack_a)->amount_of_numbers - 3)
		{
			if ((*stack_a)->top->index <= p)
			{
				push(stack_a, stack_b, "b");
				i++;
			}
			else
				rotate(stack_a, "a");
			x++;
		}
	}
}
