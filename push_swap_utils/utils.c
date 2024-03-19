/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:55 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/19 11:22:19 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree,
			int *arr_int)
{
	*stack_a = NULL;
	*stack_b = NULL;
	insert_stack_nodes(&stack_a, btree, arr_int);
	if (!stack_a)
		exit_status(1, NULL);
	clean_tree(*btree);
	ft_clean_arr_int(arr_int);
	return;
}

int		exit_status(int error, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	exit(error);
}

void	insert_stack_nodes(t_stack **stack, t_btree *btree, int *arr_int)
{
	short int size;
	short int lenght;
	t_node *new_node;

	size = 1;
	lenght = (*btree)->index;
	new_node = malloc(sizeof(t_node));
	while(size <= lenght)
	{
	}
}

void	push_top(t_stack **stack, t_node *new_node)
{

}
