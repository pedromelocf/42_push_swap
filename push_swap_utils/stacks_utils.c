/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:55 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/09 15:20:48 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree,
		int *arr_int)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		exit_status(4, "Error creating stack");
	(*stack_a)->top = NULL;
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
	{
		clean_stacks(*stack_a, *stack_b);
		exit_status(4, "Error creating stack");
	}
	(*stack_b)->top = NULL;
	insert_stack_nodes(stack_a, *btree, arr_int);
	clean_tree(*btree);
	ft_clean_arr_int(arr_int);
}

void	insert_stack_nodes(t_stack **stack_a, t_btree *btree, int *arr_int)
{
	int	stack_size;
	int	index;

	stack_size = btree->amount_of_numbers;
	(*stack_a)->amount_of_numbers = stack_size;
	while (stack_size > 0)
	{
		index = search_index(arr_int[stack_size], btree);
		push_top(stack_a, index, stack_size, arr_int[stack_size]);
		stack_size--;
	}
}

int	search_index(int value, t_btree *btree)
{
	while (btree)
	{
		if (btree->value == value)
			return (btree->index);
		else if (btree->value > value)
			btree = btree->left;
		else
			btree = btree->right;
	}
	return (1);
}

void	push_top(t_stack **stack, int index, int pos, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit_status(5, "Error creating node");
	new_node->value = value;
	new_node->index = index;
	new_node->pos_a = pos;
	new_node->pos_b = 0;
	new_node->target_pos = 0;
	new_node->cost_move = 0;
	new_node->next = NULL;
	if (!(*stack)->top)
	{
		new_node->prev = NULL;
		(*stack)->top = new_node;
	}
	else
	{
		new_node->prev = (*stack)->top;
		(*stack)->top->next = new_node;
		(*stack)->top = new_node;
	}
}

void	clean_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	while (stack_a->top)
	{
		temp = stack_a->top;
		stack_a->top = stack_a->top->prev;
		free(temp);
	}
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}
