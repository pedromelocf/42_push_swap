/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:36:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/09 15:19:44 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	ft_atoi_push(const char *nptr, int *error)
{
	long long	i;
	long long	c;
	long long	sign;

	c = 0;
	i = 0;
	sign = 1;
	*error = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		*error = 1;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		c = c * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] != '\0' || c > INT_MAX || c < INT_MIN)
		*error = 1;
	return (sign * c);
}
