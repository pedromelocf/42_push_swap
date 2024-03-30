/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:14:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/29 22:35:28 by pmelo-ca         ###   ########.fr       */
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

	x = lenstackb / 2;
	if (x * 2 != lenstackb)
		x+=1;
	while(stack_b->top->prev != NULL)
	{
		if(stack_b->top->pos_b <= x)
			stack_b->top->cost_move = stack_b->top->pos_b + stack_b->top->target_pos - 1;
		else
			stack_b->top->cost_move = 1 + lenstackb - stack_b->top->pos_b + stack_b->top->target_pos;
		stack_b->top = stack_b->top->prev;
	}
}

void	make_cheapest(t_stack **stack_a, t_stack **stack_b)
{

}

void	validate_rotates(t_stack **stack_a)
{

}
