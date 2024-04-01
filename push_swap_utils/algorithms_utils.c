/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:14:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/01 18:11:35 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_position(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	while(stack_a->top != NULL)
	{
		stack_a->top->pos_a = i;
		stack_a->top->pos_b = 0;
		stack_a->top = stack_a->top->prev;
		i++;
	}
	while(stack_b->top != NULL)
	{
		stack_b->top->pos_b = i;
		stack_a->top->pos_a = 0;
		stack_b->top = stack_b->top->prev;
		i++;
	}
}

void	calc_target_pos(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 1;
	while(stack_a->top != NULL)
		stack_a->top = stack_a->top->prev;
	if(stack_b->top->index > stack_a->top->index)
	{
		stack_b->top->target_pos = 1;
		return;
	}
	while(stack_b->top != NULL)
	{
		if(stack_b->top->index > stack_a->top->index)
			stack_b->top->target_pos = 1;
		else
		{
			while(stack_b->top->index < stack_a->top->index)
			{
				i++;
				stack_a->top = stack_a->top->next;
			}
			stack_b->top->target_pos = i;
		}
		stack_b->top = stack_b->top->prev;
	}
}

void	get_move_cost(t_stack *stack_a, t_stack *stack_b)
{
	int x;
	int y;

	x = get_half_stack_size(stack_b);
	y = get_half_stack_size(stack_a);
	while(stack_b->top->prev != NULL)
	{
		if(stack_b->top->pos_b <= x)
			stack_b->top->cost_move = stack_b->top->pos_b - 1;
		else
			stack_b->top->cost_move = 1 + lenstackb - stack_b->top->pos_b;
		if(stack_a->top->target_pos <= y)
			stack_b->top->cost_move += stack_b->top->target_pos - 1;
		else
			stack_b->top->cost_move += 1 + lenstacka - stack_b->top->target_pos;
		stack_b->top = stack_b->top->prev;
	}
}

void	make_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int lower_cost;
	int lower_cost_pos;

	lower_cost = stack_b->top->cost_move;
	lower_cost_pos = 1;
	if (lower_cost == 0)
	{
		push(stack_b, stack_a, "a");
		return;
	}
	while(stack_b->top->prev != NULL)
	{
		if(lower_cost > stack_b->top->cost_move)
		{
			lower_cost = cost;
			lower_cost_pos = stack_b->top->pos_b;
		}
		stack_b->top = stack_a->top-prev;
	}
	execute_moves(stack_a, stack_b, lower_cost_pos, lower_cost);
}

void	validate_rotates(t_stack **stack_a)
{
	int y;
	int i;

	i = 1;
	y = get_half_stack_size(stack_b);
	while(stack_a->top->index != 1)
	{
		i++;
		stack_a->top->prev;
	}
	if (i <= y)
		rotate * (i - 1);
	else
		reverse_rotate * (2 + lenstacka - i);
}

void execute_moves(stack_a, stack_b, lower_cost_pos, lower_cost)
{
	int x,
	int y;
	int new_cost;

	x = get_half_stack_size(stack_b);
	y = get_half_stack_size(stack_a);
	if (lower_cost_pos <= x)
		rotates(b) = lower_cost_pos - 1;
	else
		reverse_rotates(b) = stack_blen - lower_cost;
	new_cost = lower_cost - (rotates || reverse_rotates);
	if (new_cost <= y)
		rotates(a) = new_cost;
	else
		reverse_rotates(a) = new_cost;
}
