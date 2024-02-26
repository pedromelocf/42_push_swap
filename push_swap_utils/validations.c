/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/26 16:38:41 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_btree	*validate_arg(int argc, char **argv)
{
	t_btree	*btree;
	int		*arr_int;

	btree = NULL;
	arr_int = get_int_argc(argc, argv);
	if (!arr_int)
		return (NULL);
	btree = new_tree(argc, arr_int);
	if (!btree)
		return (NULL);
	return (btree);
}

int	*get_int_argc(int argc, char **argv)
{
	int	*arr_int;
	int	i;
	int	c;
	int	error;

	i = 1;
	c = 0;
	error = 0;
	arr_int = ft_calloc(argc, sizeof(int));
	while (i < argc)
	{
		ft_atoi_push(argv[i], &error);
		if (error)
		{
			ft_clean_arr_int(arr_int);
			return (NULL);
		}
		while (argc + c > argc)
		{
			if (ft_atoi(argv[i]) == arr_int[c - 1])
			{
				ft_clean_arr_int(arr_int);
				return (NULL);
			}
			c--;
		}
		arr_int[i - 1] = ft_atoi(argv[i]);
		i++;
		c = i - 1;
	}
	return (arr_int);
}
