/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:49:03 by senyilma          #+#    #+#             */
/*   Updated: 2023/04/11 14:42:57 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s, char const *set)
{
	char	*cuttedstring;
	int		i;
	int		endofs;

	i = 0;
	if (s != NULL)
	{
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		endofs = ft_strlen(s) - 1;
		while (endofs > i && ft_strchr(set, s[endofs]))
			endofs--;
		cuttedstring = ft_substr(s, i, endofs - i + 1);
		return (cuttedstring);
	}
	return (NULL);
}
