/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:50:45 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:13 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbrdec(int num)
{
	int	i;

	if (num >= 0 && num <= 9)
		i = ft_putchar(num + 48);
	else if (num >= 10)
	{
		i = ft_putnbrdec(num / 10);
		i += ft_putchar(num % 10 + 48);
	}
	else if (num == -2147483648)
		i = ft_putstr("-2147483648");
	else
	{
		i = ft_putchar('-');
		i += ft_putnbrdec(num * -1);
	}
	return (i);
}

int	ft_putnbrhex(unsigned int num, char x)
{
	char	*basexa;
	int		i;

	if (x == 'x')
		basexa = "0123456789abcdef";
	else
		basexa = "0123456789ABCDEF";
	if (num <= 15)
		i = ft_putchar(basexa[num % 16]);
	else
	{
		i = ft_putnbrhex(num / 16, x);
		i += ft_putchar(basexa[num % 16]);
	}
	return (i);
}
