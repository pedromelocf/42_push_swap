/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:40:15 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/08 11:28:04 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int		lower_cost;
	int		lower_cost_pos;
	t_node	*temp;

	temp = (*stack_b)->top;
	lower_cost = temp->cost_move;
	lower_cost_pos = 1;
	if (lower_cost == 0)
	{
		push(stack_b, stack_a, "a");
		return ;
	}
	while (temp != NULL)
	{
		if (lower_cost > temp->cost_move)
		{
			lower_cost = temp->cost_move;
			lower_cost_pos = temp->pos_b;
		}
		temp = temp->prev;
	}
	execute_moves(stack_a, stack_b, lower_cost_pos, lower_cost);
}

void	execute_moves(t_stack **stack_a, t_stack **stack_b, int lower_cost_pos,
		int lower_cost)
{
	int	new_cost;

	new_cost = execute_stackb_moves(lower_cost_pos, lower_cost, *stack_b);
	execute_stacka_moves(new_cost, (*stack_b)->top->target_pos, *stack_a);
	push(stack_b, stack_a, "a");
}

int	execute_stackb_moves(int lower_cost_pos, int lower_cost, t_stack *stack_b)
{
	int	x;
	int	rotates;
	int	reverse_rotates;
	int	new_cost;

	x = stack_b->amount_of_numbers / 2;
	if (x * 2 != stack_b->amount_of_numbers)
		x++;
	if (lower_cost_pos <= x)
	{
		rotates = lower_cost_pos - 1;
		new_cost = lower_cost - rotates;
		while (rotates-- > 0)
			rotate(&stack_b, "b");
	}
	else
	{
		reverse_rotates = stack_b->amount_of_numbers - lower_cost_pos + 1;
		new_cost = lower_cost - reverse_rotates;
		while (reverse_rotates-- > 0)
			reverse_rotate(&stack_b, "b");
	}
	return (new_cost);
}

void	execute_stacka_moves(int new_cost, int target_pos_b, t_stack *stack_a)
{
	int	y;
	int	rotates;
	int	reverse_rotates;

	y = stack_a->amount_of_numbers / 2;
	if (y * 2 != stack_a->amount_of_numbers)
		y++;
	if (target_pos_b <= y)
	{
		rotates = new_cost;
		while (rotates-- > 0)
			rotate(&stack_a, "a");
	}
	else
	{
		reverse_rotates = new_cost;
		while (reverse_rotates-- > 0)
			reverse_rotate(&stack_a, "a");
	}
}
