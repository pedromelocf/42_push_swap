/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/02 11:55:39 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	validate_arg(int argc, char **argv, int **arr_int)
{
	*arr_int = NULL;
	if(argc == 1)
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
			exit_status(2, "Error");
		}
		while (c > 0)
		{
			if (ft_atoi(argv[i]) == (*arr_int)[c])
			{
				ft_clean_arr_int(*arr_int);
				exit_status(2, "Error");
			}
			c--;
		}
		(*arr_int)[i] = ft_atoi(argv[i]);
		i++;
		c = i - 1;
	}
}

int	check_stack_is_sorted(t_stack *stack_a)
{
	int	i;

	i = 1;
	while(stack_a->amount_of_numbers > i)
	{
		if (stack_a->top->prev->index < stack_a->top->index)
		{
			while(stack_a->top->next != NULL)
				stack_a->top = stack_a->top->next;
			return(0);
		}
		stack_a->top = stack_a->top->prev;
		i++;
	}
	return(1);
}

