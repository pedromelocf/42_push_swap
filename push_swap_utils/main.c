/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/07 15:53:12 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc == 1)
		return (ft_printf("argc invalido\n"));
	list = validate_arg(argc, argv);
	if (!list)
		return (ft_printf("Elementos da lista invalidos\n"));
	ft_printf("Good Job :)\n");
	printf("%d\n", list->value);
	return (0);
}
