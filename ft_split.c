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
/*
char	*ft_do_string(char  *array, char const *str, int *ind, int len)
{
	int		*p_i;

	p_i = ind;
	printf("Записываю слово начиная с символа |%c| под индексом %d\n ", str[p_i], p_i);
	while (p_i < len)
	{
		array[p_i] = str[p_i];
		p_i++;
	}
	array[p_i] = '\0';
	printf("Заканчивая символом |%c| под индексом %d\n", str[p_i - 2], p_i -2);

	printf("\n--------------------- StrLength: %d (%d)---------------------------\n", len, len - 1);
	printf("\n---------------------- String: %s------------------------------\n", array);

	return (array);
}
*/

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
/*
int		ft_len_first_str(char const *str, char c)
{
	char *s = {"Hello World I'm Back and i always will be there"};

	int 		len;
	int 		end;
	int 		start;

	len = 0;
	end = 0;
//	while (!((*s == c && *(s + 1) != c && *(s + 1) != '\0') || (i == 0 && *s != c)))
//	{
//		if (*s == c || *s == '\0')
//		{
//			end = len - 1;
//			if (*s == '\0')
//				end++;
//			len = end + 1;
//			return (len);
//		}
//		len++;
//	}
	int i = 0;
	while (*s != '\0')
	{
		if (*s !=c && *s != '\0' && (*(s - 1) == c || *(s - 1) == '\0' || i == 0))
		{
			printf("\nСлово началось под индексом %d\n", i);
			start = i;
		}
		if (*(s + 1) == c || *(s + 1) == '\0')
		{
			len = i - start + 1;
			//end = i;
			printf("\nСлово длинной %d закончилось символом %c под индексом %d\n", len, *s, i);
			len = 0;
			return (start, len);
		}
		//len++;
		i++;
		s++;
	}
	return (ft_strlen(s));
}
*/
char	**ft_split(char const *s, char c)
{
	char	**matrix_for_string;
	int		num_words;
	int		i;
	int		len;
	int 	start;
	//char	*array;
	//int		kek;
	int array_index;

	//kek = 0;
	i = 0;
	start = 0;
	len = 0;
	array_index = 0;
	num_words = ft_countWords(s, c); // считает кол-во слов в целом в строке
	matrix_for_string = (char **)malloc(num_words * sizeof(char *)); // выделяем память под все строки
	if (matrix_for_string == NULL)
		return (NULL);

	printf("\n =================== В твоей строке %d слов(а) ========================\n", num_words);

	while (*s != '\0')
	{
		if (i == 0 || ((*s != c && *s != '\0') && (*(s - 1) == c || *(s - 1) == '\0')))
		{
			printf("\n ----------------------------------------------------------------\n");
			printf("\nСлово началось под индексом %d символом |-%c-| \n", i, s[0]);
			start = i;
		}
		if (*(s + 1) == c || *(s + 1) == '\0')
		{
			len = i - start + 1;
			//end = i;
			printf("\nСлово длинной %d закончилось символом |-%c-| под индексом %d\n", len, *s, i);
			printf("\nПередаю в substr строку с началом под индексом %d и длинной %d \n", start, len);
			printf("\nЗаписываю в матрицу итоговую строку в ячейку под номером %d\n", array_index);
			printf("\n ----------------------------------------------------------------\n");
			matrix_for_string[array_index] = ft_substr(s, 0, len);
			printf("\nРезультат: %s", matrix_for_string[array_index]);
			array_index++;
			len = 0;
		}
//		if (((*s == c && *(s + 1) != c && *(s + 1) != '\0') || (i == 0 && *s != c)) && (num_words > kek))
//		{
//			len = ft_len_first_str(s, c);
//			array = malloc(sizeof(*s) * (len + 1));
//			array = ft_substr(s, i, len);
//			printf("\n----------------Создаю строку начиная с индекса %d длинной %d символов--------------\n\n", i, len + 1);
//			matrix_for_string[i] = array;
//			//printf("\n----------------Передвигаем указатель на %d ячеек--------------\n\n", len + 1);
//			//s += len + 1;
//			kek++;
//		}
		i++;
		s++;
	}
	//i = 0;
//	printf("\n\n\n\n\n");
//	for (i = 0; i < num_words; i++) {
//		//for (i = 0; i < ft_strlen(matrix_for_string[i]; i++)) {
//			printf("ind %d: %s-\n", i, matrix_for_string[i]);
//		//}
//	}
	return (matrix_for_string);
}

int		main(void)
{
	char *str1 = {"Hello World I'm Back and i always will be there"};
	char *str2 = {"Hello World and i don't know what to write!!!"};
	//char *str2 = {"123 456 789 0"};

	//char *str1;

	//str1 = malloc(sizeof(*str1) * (ft_strlen
	//int *start = 0;
	//int	*end = 0;

	char **matrix = ft_split(str1, ' ');


	//ft_len_first_str(str1, ' ');

//	printf("-----------LEN OF FIRST STRING:  %d--------", ft_len_first_str(str1, ' '));

//	printf("%d\n", ft_lenstr(str1, ' '));
	//printf("WORDS: %d\n", ft_countWords(str1, ' '));
//	printf("%d\n", ft_countIndex(str1, ' ', start, end));
}
