/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:59:52 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/11/17 12:00:01 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *array, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (array[i])
	{
		while (array[i] == sep)
			i++;
		if (array[i] != '\0')
		{
			count++;
			while (array[i] && array[i] != sep)
				i++;
		}
	}
	return (count);
}

static char	*ft_copy_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_fill_words(char **ptr, const char *s, char c, int count_words)
{
	int	i;
	int	word_index;
	int	start;
	int	end;

	i = 0;
	word_index = 0;
	while (word_index < count_words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i;
		ptr[word_index] = ft_copy_word(s, start, end);
		if (!ptr[word_index])
		{
			free_split(ptr);
			return (0);
		}
		word_index++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**ptr;

	if (!s)
		return (NULL);
	count_words = ft_count_words((char *)s, c);
	ptr = (char **) malloc ((count_words + 1) * sizeof (char *));
	if (!ptr)
		return (NULL);
	if (!ft_fill_words(ptr, s, c, count_words))
		return (NULL);
	ptr[count_words] = NULL;
	return (ptr);
}
