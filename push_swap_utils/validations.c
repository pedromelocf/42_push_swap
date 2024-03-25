/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/25 20:12:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	validate_arg(int argc, char **argv, int **arr_int)
{
	*arr_int = NULL;
	if (argc == 1)
		exit_status(1, NULL);
	get_int_argc(argc, argv, arr_int);
}

void	get_int_argc(int argc, char **argv, int **arr_int)
{
	int	i;
	int	c;
	int	error;

	i = 1;
	c = 0;
	error = 0;
	*arr_int = ft_calloc(argc, sizeof(int));
	while (i < argc)
	{
		ft_atoi_push(argv[i], &error);
		if (error)
		{
			ft_clean_arr_int(*arr_int);
			exit_status(1, "Error");
		}
		while (c > 0)
		{
			if (ft_atoi(argv[i]) == (*arr_int)[c])
			{
				ft_clean_arr_int(*arr_int);
				exit_status(1, "Error");
			}
			c--;
		}
		(*arr_int)[i] = ft_atoi(argv[i]);
		i++;
		c = i - 1;
	}
}
