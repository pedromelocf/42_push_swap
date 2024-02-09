/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:43 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/09 16:01:15 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_btree	*new_tree(int argc, int *argc_arr)
{
	t_btree	*head;
	int		counter;

	counter = 1;
	head = NULL;
	while (counter < argc)
	{
		head = insert_node(head, argc_arr[counter], counter);
		counter++;
	}
	return (head);
}

t_btree	*insert_node(t_btree *btree, int arg, int counter)
{
	t_btree *new_node;

	new_node = NULL;
	if (!btree)
	{
		new_node = malloc(sizeof(t_btree));
		if (!new_node)
			return(NULL);
		new_node->value = arg;
		new_node->curr_index = counter;
		new_node->beg_index = counter;
		new_node->left = NULL;
		new_node->right = NULL;
		return(new_node);
	}
	if (arg < btree->value)
		btree->left = insert_node(btree->left, arg, counter);
	else
		btree->right = insert_node(btree->right, arg, counter);
	return(btree);
}

void	clean_tree(t_btree *btree)
{
	if(!btree)
		return;
	clean_tree(btree->left);
	clean_tree(btree->right);
	free(btree);
}