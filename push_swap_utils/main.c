/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/27 20:32:38 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_btree	*btree;
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return (ft_dprintf(2, "Missing arguments\n"));
	btree = validate_arg(argc, argv);
	if (!btree)
		return (ft_dprintf(2, "Error\n"));
	get_index(btree);
	init_stacks(stack_a, stack_b, btree);
	clean_tree(btree);
	return (0);
}
