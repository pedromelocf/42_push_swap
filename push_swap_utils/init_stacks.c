/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:55 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/26 20:39:10 by pmelo-ca         ###   ########.fr       */
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
		exit_status(5, NULL);
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		exit_status(5, NULL);
	insert_stack_nodes(stack_a, *btree, arr_int);
	clean_tree(*btree);
	ft_clean_arr_int(arr_int);
}

void	insert_stack_nodes(t_stack **stack_a, t_btree *btree, int *arr_int)
{
	int stack_size;
	int amount_of_numbers;
	int	index;

	stack_size = 0;
	amount_of_numbers = btree->amount_of_numbers;
	(*stack_a)->amount_of_numbers = amount_of_numbers;
	while(stack_size < amount_of_numbers)
	{
		index = search_index(arr_int[stack_size + 1], btree);
		push_top(stack_a, index, stack_size + 1, arr_int[stack_size + 1]);
		stack_size++;
	}
}

int		search_index(int value, t_btree *btree)
{
	while(btree)
	{
		if (btree->value == value)
			return (btree->index);
		else if (btree->value > value)
			btree = btree->left;
		else
			btree = btree->right;
	}
	return(1);
}

void	push_top(t_stack **stack, int index, int pos, int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit_status(1, NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->pos_a = pos;
	new_node->pos_b = 0;
	new_node->target_pos = 0;
	new_node->cost_move = 0;
	new_node->next = NULL;
	if(!(*stack)->top)
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

