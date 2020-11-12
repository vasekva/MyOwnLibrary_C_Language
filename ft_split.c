/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 04:49:47 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/11 22:22:34 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (words == 0 && str[i] != c)
			words++;
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
		{
			words++;
		}
		i++;
	}
	return (words);
}

void	ft_do_words(const char *s, char c, int i, char **matrix)
{
	int		array_index;
	int		len;
	int		start;
	int		num_words;

	num_words = ft_count_words(s, c);
	array_index = 0;
	start = 0;
	while (array_index < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		if (i == 0 || ((s[i] != c) && (s[i - 1] == c || s[i - 1] == '\0')))
			start = i;
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			len = i - start + 1;
			matrix[array_index++] = ft_substr(s, i - len + 1, len);
		}
		i++;
	}
	matrix[array_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**matrix_for_strings;
	int		num_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	if (!(matrix_for_strings = (char **)malloc(num_words * sizeof(char *) + 1)))
		return (NULL);
	ft_do_words(s, c, i, matrix_for_strings);
	return (matrix_for_strings);
}
git