/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/08 16:08:36 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_btree	*btree;

	if (argc == 1)
		return (ft_printf("argc invalido\n"));
	btree = validate_arg(argc, argv);
	if (!btree)
		return (ft_printf("Elementos da lista invalidos\n"));
	print_in_order(btree);
	ft_printf("Good Job :)\n");
	clean_tree(btree);
	return (0);
}

void print_in_order(t_btree *btree)
{
	if(!btree)
		return;
	print_in_order(btree->left);
	ft_printf("Valor do nó: %d\n", btree->value);
	print_in_order(btree->right);
}

void	clean_tree(t_btree *btree)
{
	if(!btree)
		return;
	clean_tree(btree->left);
	clean_tree(btree->right);
	free(btree);
}
