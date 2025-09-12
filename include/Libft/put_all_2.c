/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:38:07 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:25 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbruns(unsigned int num)
{
	int	i;

	if (num <= 9)
		i = ft_putchar(num + 48);
	else
	{
		i = ft_putnbruns(num / 10);
		i += ft_putchar(num % 10 + 48);
	}
	return (i);
}

static int	ft_putnbrhex_long(unsigned long num)
{
	char	*basexa;
	int		i;

	basexa = "0123456789abcdef";
	if (num <= 15)
		i = ft_putchar(basexa[num % 16]);
	else
	{
		i = ft_putnbrhex_long(num / 16);
		i += ft_putchar(basexa[num % 16]);
	}
	return (i);
}

int	ft_putpointer(unsigned long num)
{
	if (!num)
		return (-2);
	ft_putstr("0x");
	return (ft_putnbrhex_long(num) + 2);
}
