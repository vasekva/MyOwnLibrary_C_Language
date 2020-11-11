/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:29:59 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/10 20:07:14 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_splitnbr(int n)
{
	int num = n % 10;
	return (num);
}

int		ft_lennbr(int n)
{
	int res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	if (res > 10)
		return (0);
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	symbols[13];
	size_t			len;
	size_t			i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		printf("%d\n", n);
		write(1, "-", 1);
	}
	len = ft_lennbr(n);
	ft_bzero(symbols, 13);
	if (len == 0)
		symbols[0] = 0;
	while (len-- > 0)
	{
		int num = ft_splitnbr(n);
		symbols[len] = (unsigned char)(num + 48);
		n /= 10;
	}
	while (symbols[i] != '\0')
	{
		write(fd, &symbols[i], 1);
		i++;
	}
}

int		main(void)
{
	//int i = -12345;
	int i = -2147483648;
	//int i = 2147483647;
	ft_putnbr_fd(i, 1);
}
