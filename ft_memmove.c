/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:45:18 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/19 01:46:00 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dst;
	ptrsrc = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst == src || len == 0)
		return (dst);
	index = len;
	if (ptrsrc < ptrdest)
	{
		while (index--)
			ptrdest[index] = ptrsrc[index];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
