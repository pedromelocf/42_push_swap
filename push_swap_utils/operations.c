/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:08 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/09 15:20:55 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_source, t_stack **stack_dest, char *message)
{
	t_node	*top_a;
	t_node	*top_b;
	t_node	*old_top_b;

	if (!(*stack_source))
		return ;
	top_a = (*stack_source)->top->prev;
	top_b = (*stack_source)->top;
	old_top_b = (*stack_dest)->top;
	if (top_a != NULL)
		top_a->next = NULL;
	if (old_top_b == NULL)
		top_b->prev = NULL;
	else
	{
		old_top_b->next = top_b;
		top_b->prev = old_top_b;
	}
	(*stack_dest)->top = top_b;
	(*stack_source)->top = top_a;
	ft_printf("p%s\n", message);
}

void	swap(t_stack **stack_source, char *message)
{
	t_node	*old_top;
	t_node	*new_top;

	if (!(*stack_source))
		return ;
	if ((*stack_source)->top->prev == NULL)
		return ;
	old_top = (*stack_source)->top;
	new_top = (*stack_source)->top;
	new_top = new_top->prev;
	new_top->next = NULL;
	if (new_top->prev)
	{
		new_top->prev->next = old_top;
		old_top->prev = new_top->prev;
	}
	else
		old_top->prev = NULL;
	old_top->next = new_top;
	new_top->prev = old_top;
	(*stack_source)->top = new_top;
	ft_printf("s%s\n", message);
}

void	rotate(t_stack **stack_source, char *message)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_top;
	t_node	*temp;

	old_top = (*stack_source)->top;
	temp = old_top;
	new_top = old_top->prev;
	while (temp->prev)
		temp = temp->prev;
	old_bottom = temp;
	old_bottom->prev = old_top;
	old_top->next = old_bottom;
	old_top->prev = NULL;
	new_top->next = NULL;
	(*stack_source)->top = new_top;
	ft_printf("r%s\n", message);
}

void	reverse_rotate(t_stack **stack_source, char *message)
{
	t_node	*new_top;
	t_node	*old_top;

	old_top = (*stack_source)->top;
	while (old_top->prev != NULL)
		old_top = old_top->prev;
	new_top = old_top;
	old_top = old_top->next;
	old_top->prev = NULL;
	while (old_top->next != NULL)
		old_top = old_top->next;
	old_top->next = new_top;
	new_top->next = NULL;
	new_top->prev = old_top;
	(*stack_source)->top = new_top;
	ft_printf("rr%s\n", message);
}
