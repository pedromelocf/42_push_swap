/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:43 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/04 17:22:24 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	new_tree(int argc, int *stack_a, t_btree **btree)
{
	t_btree	*head;
	int		counter;

	counter = 1;
	head = NULL;
	*btree = NULL;
	while (counter < argc)
	{
		head = insert_node(head, stack_a[counter], counter);
		counter++;
	}
	*btree = head;
	return;
}

t_btree	*insert_node(t_btree *btree, int arg, int counter)
{
	t_btree	*tree_node;

	tree_node = NULL;
	if (!btree)
	{
		tree_node = malloc(sizeof(t_btree));
		if (!tree_node)
			exit_status(1, NULL);
		tree_node->value = arg;
		tree_node->index = 0;
		tree_node->pos = counter;
		tree_node->left = NULL;
		tree_node->right = NULL;
		return (tree_node);
	}
	if (arg < btree->value)
		btree->left = insert_node(btree->left, arg, counter);
	else
		btree->right = insert_node(btree->right, arg, counter);
	return (btree);
}

void	inorder_transversal(t_btree **btree)
{
	if (!*btree)
		return;
	inorder_transversal(&(*btree)->left);
	printf("Value: %d\n", (*btree)->value);
	inorder_transversal(&(*btree)->right);
	return;
}
