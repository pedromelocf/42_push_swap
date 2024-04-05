/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/05 17:46:23 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr_int;
	int		index;
	t_btree	*btree;
	t_stack	*stack_a;
	t_stack	*stack_b;

	index = 1;
	if (validate_arg(argc, argv, &arr_int))
	{
		ft_clean_arr_int(arr_int);
		exit_status(2, "Error");
	}
	new_tree(argc, arr_int, &btree);
	inorder_transversal(&btree, &index);
	init_stacks(&stack_a, &stack_b, &btree, arr_int);
	if (check_stack_is_sorted(stack_a))
		exit_status(7, NULL);
	algorithm(&stack_a, &stack_b);
	clean_stacks(stack_a, stack_b);
	return (0);
}
