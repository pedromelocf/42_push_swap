/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:08:16 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/01 17:16:51 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_half_stack_size(t_stack *stack_source)
{
	int x;
	int	y;

	x = 1;
	y = 0;
	while(stack_source->top->prev != NULL)
	{
		x++;
		stack_b->top = stack_b->top->prev;
	}
	y = x / 2;
	if (y * 2 != x)
		y+=1;
	return(y);
}
