/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:44:43 by senyilma          #+#    #+#             */
/*   Updated: 2023/04/13 15:15:15 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = 10 * result + ((str[i++] - 48) * sign);
		if (result > 2147483647 || result < -2147483648)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return ((int)result);
}
