/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/07 16:16:40 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*validate_arg(int argc, char **argv)
{
	t_list	*v_list;

	v_list = NULL;
	v_list = new_list(argc, argv);
	if (!v_list)
		return (NULL);
	return (v_list);
}

t_list	*new_list(int argc, char **argv)
{
	t_list	*n_list;
	t_list	*head;
	t_list	*prev;
	int		counter;

	counter = 1;
	while (counter < argc)
	{
		n_list = malloc(sizeof(t_list));
		n_list->value = ft_atoi(argv[counter]);
		n_list->next = NULL;
		if (counter == 1)
			head = n_list;
		else
			prev->next = n_list;
		prev = n_list;
		counter++;
	}
	if (!n_list)
		return (NULL);
	return (head);
}
