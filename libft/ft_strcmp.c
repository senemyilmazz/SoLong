/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:03:25 by senyilma          #+#    #+#             */
/*   Updated: 2023/04/11 15:07:06 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (0);
	return (1);
}
