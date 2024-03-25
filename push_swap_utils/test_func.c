/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:47:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/25 17:47:29 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_arr_int(int *arr_int, int lenght)
{
	int i;

	i = 1;
	while (i < lenght)
	{
		printf("Element %d from array_int:%d\n", i, arr_int[i]);
		i++;
	}
	printf("\n");
}

void print_tree(t_btree *btree)
{
	if (btree->left != NULL)
		print_tree(btree->left);
	printf("Tree node value: %d\n", btree->value);
	if (btree->right != NULL)
		print_tree(btree->right);
}

void print_tree_index(t_btree *btree)
{
	if (btree->left != NULL)
		print_tree_index(btree->left);
	printf("Tree node value: %d, Tree node index: %d\n", btree->value, btree->index);
	if (btree->right != NULL)
		print_tree_index(btree->right);
}

void print_stack(t_stack *stack)
{
	t_node *node;

	while(stack->top != NULL)
	{
		node = stack->top;
		printf("Stack node value: %d, Stack node index: %d, Stack node pos_a: %d\n", node->value, node->index, node->pos_a);
		stack->top = stack->top->prev;
	}
}
