/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:58:44 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/16 18:08:34 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*ptr;
	unsigned char	*p;

	ptr = (unsigned char *)ptr1;
	p = (unsigned char *)ptr2;
	while (num--)
	{
		if (*ptr != *p)
		{
			return (*ptr - *p);
		}
		ptr++;
		p++;
	}
	return (0);
}
