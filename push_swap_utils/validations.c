/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/08 14:38:45 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_btree	*validate_arg(int argc, char **argv)
{
	t_btree	*v_btree;

	v_btree = NULL;
	v_btree = new_tree(argc, argv);
	if (!v_btree)
		return (NULL);
	return (v_btree);
}

t_btree	*new_tree(int argc, char **argv)
{
	t_btree	*head;
	int		counter;

	counter = 1;
	head = NULL;
	while (counter < argc)
	{
		head = insert_node(head, ft_atoi(argv[counter]), counter);
		counter++;
	}
	return (head);
}

t_btree	*insert_node(t_btree *btree, int arg, int counter)
{
	t_btree *new_node;
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
