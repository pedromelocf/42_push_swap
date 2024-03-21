/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/21 12:59:41 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr_int;
	t_btree	*btree;
	t_stack *stack_a;
	t_stack *stack_b;

	validate_arg(argc, argv, &arr_int);
	print_arr_int(arr_int, argc);
	new_tree(argc, arr_int, &btree);
	print_tree(btree);
	printf("\n");
	inorder_transversal(&btree, &btree->index);
	printf("\n");
	print_tree_index(btree);
	printf("\n");
	init_stacks(&stack_a, &stack_b, &btree, arr_int);
	print_stack(stack_a);
	return (0);
}

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
		printf("Stack node index: %d, Stack node pos_a: %d\n", node->index, node->pos_a);
		stack->top = stack->top->prev;
	}
}
