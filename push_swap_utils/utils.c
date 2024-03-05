/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:55 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/04 21:52:54 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_tree(t_btree *btree)
{
	if (!btree)
		return ;
	clean_tree(btree->left);
	clean_tree(btree->right);
	free(btree);
}

int		exit_status(int error, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	exit(error);
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree,
			int *arr_int)
{
	stack_a = NULL;
	stack_b = NULL;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		exit_status(1, NULL);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		exit_status(1, NULL);
	clean_tree(*btree);
	ft_clean_arr_int(arr_int);
	return;
}
