/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:43 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/19 18:56:08 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	new_tree(int argc, int *arr_int, t_btree **btree)
{
	t_btree	*head;
	int		counter;

	counter = 1;
	head = NULL;
	*btree = NULL;
	while (counter < argc)
	{
		head = insert_tree_node(head, arr_int[counter], counter);
		counter++;
	}
	*btree = head;
	if (!*btree)
		exit_status(1, NULL);
	return;
}

t_btree	*insert_tree_node(t_btree *btree, int arg, int counter)
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
		tree_node->left = NULL;
		tree_node->right = NULL;
		return (tree_node);
	}
	if (arg < btree->value)
		btree->left = insert_tree_node(btree->left, arg, counter);
	else
		btree->right = insert_tree_node(btree->right, arg, counter);
	return (btree);
}

void	inorder_transversal(t_btree **btree, int *index)
{
	if (!*btree)
		return;
	inorder_transversal(&(*btree)->left, index);
	(*btree)->index = ++(*index);
	inorder_transversal(&(*btree)->right, index);
}

void	clean_tree(t_btree *btree)
{
	if (!btree)
		return ;
	clean_tree(btree->left);
	clean_tree(btree->right);
	free(btree);
}
