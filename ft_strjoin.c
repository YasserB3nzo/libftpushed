/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:06:56 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/17 21:26:04 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_string;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup((char *)s2));
	else if (!s2)
		return (ft_strdup((char *)s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len_s1 + 1);
	ft_strlcat(new_string, s2, len_s2 + len_s1 + 1);
	return (new_string);
}
