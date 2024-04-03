/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_get_next_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:56 by senyilma          #+#    #+#             */
/*   Updated: 2023/04/11 16:20:05 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gn_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gn_strjoin(char *s1, char *s2)
{
	char	*s1s2;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	s1s2 = (char *)malloc((ft_strlen(s1)+ ft_strlen(s2)+1) * sizeof(char));
	if (!s1s2)
		return (NULL);
	while (s1[++i] != 0)
		s1s2[i] = s1[i];
	while (s2[++j] != 0)
		s1s2[i + j] = s2[j];
	s1s2[i + j] = '\0';
	free(s1);
	return (s1s2);
}

int	gn_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*gn_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	substring = (char *)malloc((len) * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len -1 && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	if (substring == NULL)
		return (NULL);
	return (substring);
}
