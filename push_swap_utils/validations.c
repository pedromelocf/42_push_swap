/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:34:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/08 17:45:33 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_arg(int argc, char **argv, int **arr_int)
{
	*arr_int = NULL;
	if (argc == 1)
		exit_status(1, NULL);
	if (get_int_argc(argc, argv, arr_int))
		return (1);
	return (0);
}

int	get_int_argc(int argc, char **argv, int **arr_int)
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
			return (1);
		while (c > 0)
		{
			if (ft_atoi(argv[i]) == (*arr_int)[c])
				return (1);
			c--;
		}
		(*arr_int)[i] = ft_atoi(argv[i]);
		i++;
		c = i - 1;
	}
	return (0);
}

int	check_stack_is_sorted(t_stack *stack_a)
{
	int		i;
	t_node	*temp;

	temp = stack_a->top;
	i = 1;
	while (stack_a->amount_of_numbers > i)
	{
		if (temp->prev->index < temp->index)
		{
			while (temp->next != NULL)
				temp = temp->next;
			return (0);
		}
		temp = temp->prev;
		i++;
	}
	return (1);
}

void	validate_rotates(t_stack **stack_a)
{
	int	y;
	int	i;

	i = 1;
	y = (*stack_a)->amount_of_numbers / 2;
	if (y * 2 != (*stack_a)->amount_of_numbers)
		y++;
	while ((*stack_a)->top->index != 1)
	{
		(*stack_a)->top = (*stack_a)->top->prev;
		i++;
	}
	while ((*stack_a)->top->next != NULL)
		(*stack_a)->top = (*stack_a)->top->next;
	if (i <= y)
	{
		while (i-- > 1)
			rotate(stack_a, "a");
	}
	else
	{
		while ((*stack_a)->amount_of_numbers - i++ >= 0)
			reverse_rotate(stack_a, "a");
	}
}
