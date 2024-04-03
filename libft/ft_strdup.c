/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:48:16 by senyilma          #+#    #+#             */
/*   Updated: 2022/12/23 11:49:46 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*coppiedarray;
	size_t	len;

	len = ft_strlen(s1) + 1;
	coppiedarray = malloc(len * sizeof(char));
	if (!coppiedarray)
		return (NULL);
	coppiedarray = ft_memcpy(coppiedarray, s1, len);
	return (coppiedarray);
}
