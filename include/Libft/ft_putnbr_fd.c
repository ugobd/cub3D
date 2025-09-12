/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:27:47 by thphilip          #+#    #+#             */
/*   Updated: 2025/03/24 15:26:58 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
		i = ft_putstr_fd("-2147483648", fd);
	else if (n >= 0 && n <= 9)
		i = ft_putchar_fd(n + '0', fd);
	else if (n > 9)
	{
		i = ft_putnbr_fd(n / 10, fd);
		i += ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		i = ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(n * -1, fd);
	}
	return (i);
}
