/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:14:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/02 11:26:05 by pmelo-ca         ###   ########.fr       */
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
		if (stack_a->top->prev == NULL)
			break;
		stack_a->top = stack_a->top->prev;
		i++;
	}
	while(stack_b->top != NULL)
	{
		stack_b->top->pos_b = i;
		stack_b->top->pos_a = 0;
		if (stack_b->top->prev == NULL)
			break;
		stack_b->top = stack_b->top->prev;
		i++;
	}
}

void	calc_target_pos(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	while(stack_b->top->next != NULL)
		stack_b->top = stack_b->top->next;
	if(stack_b->top->index > stack_a->top->index)
	{
		stack_b->top->target_pos = 1;
		return;
	}
	while(stack_b->top->prev != NULL)
	{
		i = get_stack_size(stack_a);
		if(stack_b->top->index > stack_a->top->index)
			stack_b->top->target_pos = 1;
		else
		{
			while(stack_b->top->index < stack_a->top->index)
			{
				i--;
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

	x = get_stack_size(stack_b) / 2;
	if (x * 2 != get_stack_size(stack_b))
		x++;
	y = get_stack_size(stack_a) / 2;
	if (y * 2 != get_stack_size(stack_a))
		y++;
	while(stack_b->top->prev != NULL)
	{
		if(stack_b->top->pos_b <= x)
			stack_b->top->cost_move = stack_b->top->pos_b - 1;
		else
			stack_b->top->cost_move = 1 + get_stack_size(stack_b) - stack_b->top->pos_b;
		if(stack_a->top->target_pos <= y)
			stack_b->top->cost_move += stack_b->top->target_pos - 1;
		else
			stack_b->top->cost_move += 1 + get_stack_size(stack_a) - stack_b->top->target_pos;
		stack_b->top = stack_b->top->prev;
	}
}

void	make_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int lower_cost;
	int lower_cost_pos;

	lower_cost = (*stack_b)->top->cost_move;
	lower_cost_pos = 1;
	if (lower_cost == 0)
	{
		push(stack_b, stack_a, "a");
		return;
	}
	while((*stack_b)->top->prev != NULL)
	{
		if(lower_cost > (*stack_b)->top->cost_move)
		{
			lower_cost = (*stack_b)->top->cost_move;
			lower_cost_pos = (*stack_b)->top->pos_b;
		}
		(*stack_b)->top = (*stack_a)->top->prev;
	}
	execute_moves(stack_a, stack_b, lower_cost_pos, lower_cost);
}

void	validate_rotates(t_stack **stack_a)
{
	int y;
	int i;

	i = 0;
	y = get_stack_size(*stack_a) / 2;
	if (y * 2 != get_stack_size(*stack_a))
		y++;
	while((*stack_a)->top->index != 1)
	{
		i++;
		(*stack_a)->top = (*stack_a)->top->prev;
	}
	if (i <= y)
	{
		while (i > 0)
		{
			rotate(stack_a, "a");
			i--;
		}
	}
	else
	{
		while (get_stack_size(*stack_a) - i >= 0)
		{
			reverse_rotate(stack_a, "a");
			i--;
		}
	}
}

void	execute_moves(t_stack **stack_a, t_stack **stack_b, int lower_cost_pos, int lower_cost)
{
	int x;
	int y;
	int new_cost;
	int rotates;
	int reverse_rotates;

	x = get_stack_size(*stack_b) / 2;
	if (x * 2 != get_stack_size(*stack_b))
		x++;
	y = get_stack_size(*stack_a) / 2;
	if (y * 2 != get_stack_size(*stack_a))
		y++;
	if (lower_cost_pos <= x)
	{
		rotates = lower_cost_pos - 1;
		while(rotates > 0)
		{
			rotate(stack_b, "b");
			rotates--;
		}
		new_cost = lower_cost - rotates;
	}
	else
	{
		reverse_rotates = get_stack_size(*stack_b) - lower_cost;
		while(reverse_rotates > 0)
		{
			reverse_rotate(stack_b, "b");
			reverse_rotates--;
		}
		new_cost = lower_cost - reverse_rotates;
	}
	if (new_cost <= y)
	{
		rotates = new_cost;
		while(rotates > 0)
		{
			rotate(stack_a, "a");
			rotates--;
		}
	}
	else
	{
		reverse_rotates = new_cost;
		while(reverse_rotates > 0)
		{
			reverse_rotate(stack_a, "a");
			reverse_rotates--;
		}
	}
	push(stack_b, stack_a, "a");
}

