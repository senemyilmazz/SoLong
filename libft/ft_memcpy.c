/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:46:27 by senyilma          #+#    #+#             */
/*   Updated: 2022/12/23 15:07:09 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (n == 0 || dest == source)
		return (dest);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return ((void *)dest);
}
