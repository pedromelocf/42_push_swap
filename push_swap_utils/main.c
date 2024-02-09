/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/09 16:01:04 by pmelo-ca         ###   ########.fr       */
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
	ft_printf("Good Job :)\n");
	clean_tree(btree);
	return (0);
}
