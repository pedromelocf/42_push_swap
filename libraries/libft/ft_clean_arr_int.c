/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_arr_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:26:00 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/19 23:41:28 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_clean_arr_int(int *arr_int)
{
	if (!arr_int)
		return ;
	if (arr_int)
		free(arr_int);
	arr_int = NULL;
}
