/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/19 14:11:18 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_btree	*validate_arg(int argc, char **argv)
{
	t_btree	*btree;
	int		*stack_a;

	btree = NULL;
	stack_a = get_int_argc(argc, argv);
	if (!stack_a)
		return(NULL);
	btree = new_tree(argc, stack_a);
	if (!btree)
		return (NULL);
	return (btree);
}

int	*get_int_argc(int argc, char **argv)
{
	int	*stack_a;
	int		i;
	int		c;
	int		error;

	i = 1;
	c = 0;
	error = 0;
	stack_a = ft_calloc(argc, sizeof(int));
	while (i < argc)
	{
		ft_atoi_push(argv[i], &error);
		if (error)
		{
			ft_clean_arr_int(stack_a);
			return(NULL);
		}
		while (argc + c > argc)
		{
			if (ft_atoi(argv[i]) == stack_a[c - 1])
			{
				ft_clean_arr_int(stack_a);
				return(NULL);
			}
			c--;
		}
		stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
		c = i - 1;
	}
	return(stack_a);
}
