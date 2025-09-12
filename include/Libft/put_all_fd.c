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

int	ft_putnbrdec_fd(int num, int fd)
{
	int	i;

	if (num >= 0 && num <= 9)
		i = ft_putchar_fd(num + 48, fd);
	else if (num >= 10)
	{
		i = ft_putnbrdec_fd(num / 10, fd);
		i += ft_putchar_fd(num % 10 + 48, fd);
	}
	else if (num == -2147483648)
		i = ft_putstr_fd("-2147483648", fd);
	else
	{
		i = ft_putchar_fd('-', fd);
		i += ft_putnbrdec_fd(num * -1, fd);
	}
	return (i);
}

int	ft_putnbrhex_fd(unsigned int num, char x, int fd)
{
	char	*basexa;
	int		i;

	if (x == 'x')
		basexa = "0123456789abcdef";
	else
		basexa = "0123456789ABCDEF";
	if (num <= 15)
		i = ft_putchar_fd(basexa[num % 16], fd);
	else
	{
		i = ft_putnbrhex_fd(num / 16, x, fd);
		i += ft_putchar_fd(basexa[num % 16], fd);
	}
	return (i);
}

int	ft_putnbruns_fd(unsigned int num, int fd)
{
	int	i;

	if (num <= 9)
		i = ft_putchar_fd(num + 48, fd);
	else
	{
		i = ft_putnbruns_fd(num / 10, fd);
		i += ft_putchar_fd(num % 10 + 48, fd);
	}
	return (i);
}

static int	ft_putnbrhex_long_fd(unsigned long num, int fd)
{
	char	*basexa;
	int		i;

	basexa = "0123456789abcdef";
	if (num <= 15)
		i = ft_putchar_fd(basexa[num % 16], fd);
	else
	{
		i = ft_putnbrhex_long_fd(num / 16, fd);
		i += ft_putchar_fd(basexa[num % 16], fd);
	}
	return (i);
}

int	ft_putpointer_fd(unsigned long num, int fd)
{
	if (!num)
		return (-2);
	ft_putstr_fd("0x", fd);
	return (ft_putnbrhex_long_fd(num, fd) + 2);
}
