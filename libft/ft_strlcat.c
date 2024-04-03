/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:48:25 by senyilma          #+#    #+#             */
/*   Updated: 2022/12/22 20:55:13 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!dest && !size)
		return (0);
	i = ft_strlen(dest);
	if (i >= size)
		return (size + ft_strlen(source));
	while (source[j] && (i + j) < (size - 1))
	{
		dest[i + j] = source[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(source));
}
