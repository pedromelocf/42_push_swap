/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:08 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/29 21:02:06 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_source, t_stack **stack_dest)
{
	t_node *temp;

	if(!(*stack_source))
		return;
	temp = dup_node((*stack_source)->top);
	(*stack_source)->top = (*stack_source)->top->prev;
	(*stack_source)->top->next = NULL;
	if ((*stack_dest)->top == NULL)
		temp->prev = NULL;
	else
	{
		(*stack_dest)->top->next = temp;
		temp->prev = (*stack_dest)->top;
	}
	(*stack_dest)->top = temp;
}

void	swap(t_stack **stack_source)
{
	t_node *temp;

	if(!(*stack_source))
		return;
	if((*stack_source)->top->prev == NULL)
		return;
	temp = dup_node((*stack_source)->top);
	if(temp == NULL)
		exit_status(6, NULL);
	(*stack_source)->top = (*stack_source)->top->prev;
	(*stack_source)->top->next = NULL;
	(*stack_source)->top->prev->next = temp;
	temp->prev = (*stack_source)->top->prev;
	temp->next = (*stack_source)->top;
	(*stack_source)->top->prev = temp;
}

void rotate(t_stack **stack_source)
{
	t_node *temp;

	temp = dup_node((*stack_source)->top);
	if(temp == NULL)
		exit_status(6, NULL);
	while((*stack_source)->top->prev != NULL)
		(*stack_source)->top = (*stack_source)->top->prev;
	temp->next = (*stack_source)->top;
	temp->prev = NULL;
	(*stack_source)->top->prev = temp;
	while((*stack_source)->top->next != NULL)
		(*stack_source)->top = (*stack_source)->top->next;
	(*stack_source)->top = (*stack_source)->top->prev;
	(*stack_source)->top->next = NULL;
}

void	reverse_rotate(t_stack **stack_source)
{
	t_node *temp;

	temp = dup_node((*stack_source)->top);
	while((*stack_source)->top->prev != NULL)
		(*stack_source)->top = (*stack_source)->top->prev;
	if(temp == NULL)
		exit_status(6, NULL);
	temp->next = (*stack_source)->top;
	(*stack_source)->top->next->prev = NULL;
	(*stack_source)->top->prev = temp;
	(*stack_source)->top->next = NULL;
	while((*stack_source)->top->next != NULL)
		(*stack_source)->top = (*stack_source)->top->next;
	(*stack_source)->top->prev->next = temp;
}

t_node *dup_node(t_node *node_source)
{
	t_node *temp;

	temp = malloc(sizeof(t_node));
	temp->value = node_source->value;
	temp->index = node_source->index;
	temp->pos_a = node_source->pos_a;
	temp->pos_b = node_source->pos_b;
	temp->target_pos = node_source->target_pos;
	temp->cost_move = node_source->cost_move;
	temp->prev = node_source->prev;
	temp->next = node_source->next;
	return(temp);
}
