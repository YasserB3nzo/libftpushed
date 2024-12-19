/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:49:16 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/16 22:49:16 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l = 1;
	while (n != 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static unsigned int	check_sign(int num)
{
	int	s;

	s = -1;
	if (num < 0)
		return ((unsigned int)(num * s));
	return ((unsigned int)num);
}

char	*ft_itoa(int n)
{
	int				l;
	char			*ptr;
	unsigned int	num;

	l = len_n(n);
	ptr = (char *)malloc((l + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	num = check_sign(n);
	ptr[l] = '\0';
	if (n == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	if (n < 0)
		ptr[0] = '-';
	while (num > 0)
	{
		ptr[--l] = (num % 10) + '0';
		num /= 10;
	}
	return (ptr);
}
