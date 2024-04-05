/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:08:16 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/05 17:15:36 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_size(t_stack *stack_source)
{
	int	x;

	x = 1;
	while (stack_source->top->prev != NULL)
	{
		x++;
		stack_source->top = stack_source->top->prev;
	}
	return (x);
}
