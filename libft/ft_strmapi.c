/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:48:37 by senyilma          #+#    #+#             */
/*   Updated: 2022/12/27 14:36:57 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*returnarray;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	returnarray = (char *)malloc(sizeof(char) * (len + 1));
	if (!returnarray)
		return (NULL);
	i = 0;
	while (s[i])
	{
		returnarray[i] = f(i, s[i]);
		i++;
	}
	returnarray[i] = '\0';
	return (returnarray);
}
