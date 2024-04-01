/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:43 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/01 16:56:48 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	new_tree(int argc, int *arr_int, t_btree **btree)
{
	int		counter;

	counter = 1;
	*btree = NULL;
	while (counter < argc)
	{
		insert_tree_node(btree, arr_int[counter], counter, argc);
		counter++;
	}
	if (!*btree)
		exit_status(3, "Error creating tree");
}

void	insert_tree_node(t_btree **btree, int arg, int counter, int argc)
{
	if (!*btree)
	{
		*btree = malloc(sizeof(t_btree));
		if (!*btree)
			exit_status(3, "Error creating tree");
		(*btree)->amount_of_numbers = argc - 1;
		(*btree)->value = arg;
		(*btree)->index = 0;
		(*btree)->left = NULL;
		(*btree)->right = NULL;
		return;
	}
	if (arg < (*btree)->value)
		insert_tree_node(&(*btree)->left, arg, counter, argc);
	else
		insert_tree_node(&(*btree)->right, arg, counter, argc);
}

void	inorder_transversal(t_btree **btree, int *index)
{
	if (!*btree)
		return;
	inorder_transversal(&(*btree)->left, index);
	(*btree)->index = (*index)++;
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

