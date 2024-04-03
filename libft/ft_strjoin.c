/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:48:22 by senyilma          #+#    #+#             */
/*   Updated: 2023/04/11 14:12:59 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
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
