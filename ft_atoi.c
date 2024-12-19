/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:04:57 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/20 00:11:17 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nb)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || (nb[i] == 32))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nb[i]))
	{
		res = (res * 10) + (nb[i] - '0');
		i++;
	}
	if (res > LONG_MAX)
		return (0 - (sign == 1));
	return (res * sign);
}
