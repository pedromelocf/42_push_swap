/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:14:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/03 13:04:40 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_position(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_node *temp = stack_a->top;

	i = 1;
	while(temp != NULL)
	{
		temp->pos_a = i;
		temp->pos_b = 0;
		temp = temp->prev;
		i++;
	}
	stack_a->amount_of_numbers = i - 1;
	i = 1;
	temp = stack_b->top;
	while(temp != NULL)
	{
		temp->pos_b = i;
		temp->pos_a = 0;
		temp = temp->prev;
		i++;
	}
	stack_b->amount_of_numbers = i - 1;
}

void	calc_target_pos(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	t_node *temp_a = stack_a->top;
	t_node *temp_b = stack_b->top;
	while(temp_b != NULL)
	{
		while(temp_a->prev != NULL)
			temp_a = temp_a->prev;
		i = stack_a->amount_of_numbers;
		if(temp_b->index > temp_a->index)
			temp_b->target_pos = 1;
		else
		{
			while(temp_b->index < temp_a->index)
			{
				i--;
				temp_a = temp_a->next;
				if (i == 0)
					break;
			}
			temp_b->target_pos = i + 1;
		}
		temp_b = temp_b->prev;
		temp_a = stack_a->top;
	}
}

void	get_move_cost(t_stack *stack_a, t_stack *stack_b)
{
	int x;
	int y;

	t_node *temp = stack_b->top;
	x = stack_b->amount_of_numbers / 2;
	if (x * 2 != stack_b->amount_of_numbers)
		x++;
	y = stack_a->amount_of_numbers / 2;
	if (y * 2 != stack_a->amount_of_numbers)
		y++;
	while(temp != NULL)
	{
		if(temp->pos_b <= x)
			temp->cost_move = temp->pos_b - 1;
		else
			temp->cost_move = 1 + stack_b->amount_of_numbers - temp->pos_b;
		if(stack_a->top->target_pos <= y)
			temp->cost_move += temp->target_pos - 1;
		else
			temp->cost_move += 1 + stack_a->amount_of_numbers - temp->target_pos;
		temp = temp->prev;
	}
}

void	make_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int lower_cost;
	int lower_cost_pos;
	t_node *temp = (*stack_b)->top;

	lower_cost = temp->cost_move;
	lower_cost_pos = 1;
	if (lower_cost == 0)
	{
		push(stack_b, stack_a, "a");
		return;
	}
	while(temp->prev != NULL)
	{
		if(lower_cost > temp->cost_move)
		{
			lower_cost = temp->cost_move;
			lower_cost_pos = temp->pos_b;
		}
		temp = temp->prev;
	}
	execute_moves(stack_a, stack_b, lower_cost_pos, lower_cost);
}


void	execute_moves(t_stack **stack_a, t_stack **stack_b, int lower_cost_pos, int lower_cost)
{
	int x;
	int y;
	int new_cost;
	int rotates;
	int reverse_rotates;

	x = (*stack_b)->amount_of_numbers / 2;
	if (x * 2 != (*stack_b)->amount_of_numbers)
		x++;
	y = (*stack_a)->amount_of_numbers / 2;
	if (y * 2 != (*stack_a)->amount_of_numbers)
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
		reverse_rotates = (*stack_b)->amount_of_numbers - lower_cost;
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

void	validate_rotates(t_stack **stack_a)
{
	int y;
	int i;

	i = 0;
	y =(*stack_a)->amount_of_numbers / 2;
	if (y * 2 !=(*stack_a)->amount_of_numbers)
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
		while ((*stack_a)->amount_of_numbers - i >= 0)
		{
			reverse_rotate(stack_a, "a");
			i++;
		}
	}
}
