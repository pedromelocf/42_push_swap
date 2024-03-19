/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/18 14:17:09 by pmelo-ca         ###   ########.fr       */
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
	new_tree(argc, arr_int, &btree);
	inorder_transversal(&btree, &btree->index);
	init_stacks(&stack_a, &stack_b, &btree, arr_int);
	return (0);
}
