/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 05:39:12 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/08 19:30:25 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_neg(int n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

static size_t	ft_numsize(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	size_t	len;

	len = ft_numsize(n);
	neg = (n < 0);
	len += neg;
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (neg)
		str[0] = '-';
	while (n)
	{
		str[--len] = is_neg(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
