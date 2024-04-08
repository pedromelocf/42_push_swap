/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:14:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/08 11:28:16 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_position(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_node	*temp;

	temp = stack_a->top;
	i = 1;
	while (temp != NULL)
	{
		temp->pos_a = i;
		temp->pos_b = 0;
		temp = temp->prev;
		i++;
	}
	stack_a->amount_of_numbers = i - 1;
	i = 1;
	temp = stack_b->top;
	while (temp != NULL)
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
	t_node	*temp;

	temp = stack_b->top;
	while (temp)
	{
		temp->target_pos = get_target_pos(stack_a, temp->index);
		temp = temp->prev;
	}
}

int	get_target_pos(t_stack *stack_a, int b_index)
{
	int		target_posi;
	int		target_index;
	t_node	*temp_a;

	target_posi = -1;
	temp_a = stack_a->top;
	target_index = INT_MAX;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_posi = temp_a->pos_a;
		}
		temp_a = temp_a->prev;
	}
	if (target_posi == -1)
		return (get_smaller_index_pos(stack_a));
	return (target_posi);
}

int	get_smaller_index_pos(t_stack *stack_a)
{
	int		smaller_index;
	t_node	*temp;
	t_node	*temp_top;

	temp = stack_a->top;
	temp_top = stack_a->top;
	smaller_index = stack_a->top->index;
	while (stack_a->top)
	{
		if (stack_a->top->index < smaller_index)
		{
			smaller_index = stack_a->top->index;
			temp = stack_a->top;
		}
		stack_a->top = stack_a->top->prev;
	}
	stack_a->top = temp_top;
	return (temp->pos_a);
}

void	get_move_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		x;
	int		y;
	t_node	*temp;

	temp = stack_b->top;
	x = stack_b->amount_of_numbers / 2;
	if (x * 2 != stack_b->amount_of_numbers)
		x++;
	y = stack_a->amount_of_numbers / 2;
	if (y * 2 != stack_a->amount_of_numbers)
		y++;
	while (temp != NULL)
	{
		if (temp->pos_b <= x)
			temp->cost_move = temp->pos_b - 1;
		else
			temp->cost_move = 1 + stack_b->amount_of_numbers - temp->pos_b;
		if (temp->target_pos <= y)
			temp->cost_move += temp->target_pos - 1;
		else
			temp->cost_move += 1 + stack_a->amount_of_numbers
				- temp->target_pos;
		temp = temp->prev;
	}
}

void	validate_rotates(t_stack **stack_a)
{
	int	y;
	int	i;

	i = 1;
	y = (*stack_a)->amount_of_numbers / 2;
	if (y * 2 != (*stack_a)->amount_of_numbers)
		y++;
	while ((*stack_a)->top->index != 1)
	{
		(*stack_a)->top = (*stack_a)->top->prev;
		i++;
	}
	while ((*stack_a)->top->next != NULL)
		(*stack_a)->top = (*stack_a)->top->next;
	if (i <= y)
	{
		while (i-- > 1)
			rotate(stack_a, "a");
	}
	else
	{
		while ((*stack_a)->amount_of_numbers - i++ >= 0)
			reverse_rotate(stack_a, "a");
	}
}
