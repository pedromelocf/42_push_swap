/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:17 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/05 16:23:16 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_buf(char const *s1, char const *s2)
{
	char	*joined_string;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2 && s1)
	{
		free((char *)s1);
		return (NULL);
	}
	joined_string = ft_strjoin(s1, s2);
	if (!joined_string)
	{
		free((char *)s1);
		return (NULL);
	}
	free((char *)s1);
	return (joined_string);
}

char	*ft_strdup(const char *s)
{
	char	*newstring;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s[index1])
		index1++;
	newstring = (char *)malloc(sizeof(char) * index1 + 1);
	if (!newstring)
		return (NULL);
	while (index2 < index1)
	{
		newstring[index2] = s[index2];
		index2++;
	}
	newstring[index2] = '\0';
	return (newstring);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}
