/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/09 11:57:43 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_btree	*validate_arg(int argc, char **argv)
{
	t_btree	*v_btree;
	int		*argc_arr;

	v_btree = NULL;
	argc_arr = get_int_argc(argc, argv);
	if (!argc_arr)
		return(NULL);
	v_btree = new_tree(argc, argc_arr);
	if (!v_btree)
		return (NULL);
	return (v_btree);
}

int	*get_int_argc(int argc, char **argv)
{
	int	*argc_arr;
	int		i;
	int		c;
	int		error;

	i = 1;
	c = 0;
	error = 0;
	argc_arr = malloc(sizeof(int) * argc);
	while (i < argc)
	{
		ft_atoi_push(argv[i], &error);
		if (error)
			return(NULL);
		while (argc + c > argc)
		{
			if (ft_atoi(argv[i]) == argc_arr[c - 1])
				return(NULL);
			c--;
		}
		argc_arr[i - 1] = ft_atoi(argv[i]);
		i++;
		c = i - 1;
	}
	return(argc_arr);
}

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
