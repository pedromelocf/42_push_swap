/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/07 16:19:38 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	int counter = 1;

	if (argc == 1)
		return (ft_printf("argc invalido\n"));
	list = validate_arg(argc, argv);
	if (!list)
		return (ft_printf("Elementos da lista invalidos\n"));
	ft_printf("Good Job :)\n");
	while(counter < argc)
	{
		ft_printf("Element %d from list:%d\n", counter, list->value);
		counter++;
		list = list->next;
	}
	return (0);
}
