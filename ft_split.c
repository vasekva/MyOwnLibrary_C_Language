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

int		ft_countWords(char const *str, char c)
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
	printf("\n-------------------- Numbers of String: %d -------------------\n", words);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix_for_string;
	int		num_words;
	int		i;
	int		len;
	int 	start;
	int 	array_index;

	i = 0;
	start = 0;
	len = 0;
	array_index = 0;
	if (!s)
		return (NULL);
	num_words = ft_countWords(s, c); // считает кол-во слов в целом в строке
	matrix_for_string = (char **)malloc(num_words * sizeof(char *) + 1); // выделяем память под все строки
	if (matrix_for_string == NULL)
		return (NULL);

	printf("\n =================== В твоей строке %d слов(а) ========================\n", num_words);

	while (array_index < num_words)
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (i == 0 || ((s[i] != c) && (s[i - 1] == c || s[i - 1] == '\0')))
		{
			printf("\n ----------------------------------------------------------------\n");
			printf("\nСлово началось под индексом %d символом |-%c-| \n", i, s[i]);
			start = i;
		}
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			len = i - start + 1;
			//end = i;
			printf("\nСлово длинной %d закончилось символом |-%c-| под индексом %d\n", len, s[i], i);
			printf("\nПередаю в substr строку с началом под индексом %d и длинной %d \n", start, len);
			printf("\nЗаписываю в матрицу итоговую строку в ячейку под номером %d\n", array_index);
			printf("\n ----------------------------------------------------------------\n");
			matrix_for_string[array_index] = ft_substr(s, i - len + 1, len);
			printf("\nРезультат: %s", matrix_for_string[array_index]);
			array_index++;
			len = 0;
		}
		i++;
	}
	matrix_for_string[array_index] = NULL;
	return (matrix_for_string);
}

int		main(void)
{
	char *str1 = {"Hello7World7I'm7Back7and7i always will be there                             "};
	//char *str2 = {"Hello World and i don't know what to write!!!"};
	//char *str2 = {"123 456 789 0"};

	//char *str1;

	//str1 = malloc(sizeof(*str1) * (ft_strlen
	//int *start = 0;
	//int	*end = 0;

	char **matrix = ft_split(str1, '7');

}
