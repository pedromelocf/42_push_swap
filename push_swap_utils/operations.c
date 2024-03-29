/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:08 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/29 10:52:11 by pmelo-ca         ###   ########.fr       */
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
	if ((*stack_dest)->top == NULL)
		temp->prev = NULL;
	else
		temp->prev = (*stack_dest)->top;
	temp->next = NULL;
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

}
