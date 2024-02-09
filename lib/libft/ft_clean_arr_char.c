/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_arr_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:41:36 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/09 11:42:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_clean_arr_char(char **arr_char)
{
	int	x;

	x = 0;
	if (!arr_char)
		return ;
	while (arr_char[x])
		free(arr_char[x++]);
	if (arr_char)
		free(arr_char);
}
