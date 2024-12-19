/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:41:48 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/16 17:43:58 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (size <= ldst)
		return (size + lsrc);
	while (src[i] && ldst + i < size - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ldst + lsrc);
}
