/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:36:34 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/26 12:22:41 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	ft_atoi_push(const char *nptr, int *error)
{
	long long	i;
	long long 	c;
	long long 	sign;

	c = 0;
	i = 0;
	sign = 1;
	*error = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		c = c * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] != '\0' || c > INT_MAX)
		*error = 1;
	return (sign * c);
}
