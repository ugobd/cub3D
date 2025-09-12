/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:32:11 by thphilip          #+#    #+#             */
/*   Updated: 2025/05/14 15:45:15 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_conversion(const char str, va_list tab, int fd)
{
	int	val;

	if (str == 'c')
		val = ft_putchar_fd(va_arg(tab, int), fd);
	else if (str == 's')
		val = ft_putstr_fd(va_arg(tab, char *), fd);
	else if (str == 'p')
		val = ft_putpointer_fd(va_arg(tab, unsigned long), fd);
	else if (str == 'd' || str == 'i')
		val = ft_putnbrdec_fd(va_arg(tab, int), fd);
	else if (str == 'u')
		val = ft_putnbruns_fd(va_arg(tab, unsigned int), fd);
	else if (str == 'x' || str == 'X')
		val = ft_putnbrhex_fd(va_arg(tab, unsigned int), str, fd);
	else if (str == '%')
		val = ft_putchar_fd('%', fd);
	else
		val = -3;
	return (val);
}

static int	def_start(const char *str, int *i, int *val)
{
	if (!str)
		return (-1);
	*i = 0;
	*val = 0;
	return (0);
}

static int	verif_param(const char *str, int i, va_list tab, int fd)
{
	int	tmp;

	tmp = get_conversion(str[i + 1], tab, fd);
	if (tmp == -3 && str[i + 1])
	{
		ft_putchar_fd(str[i], fd);
		ft_putchar_fd(str[i + 1], fd);
		return (2);
	}
	else if (tmp == -3 && !str[i + 1])
		return (-1);
	else if (tmp == -1)
		return (ft_putstr_fd("(null)", fd));
	else if (tmp == -2)
		return (ft_putstr_fd("(nil)", fd));
	else
		return (tmp);
}

int	ft_printf_fd(const char *str, int fd, ...)
{
	int		i;
	int		val;
	int		tmp;
	va_list	tab;

	if (def_start(str, &i, &val) == -1)
		return (-1);
	va_start(tab, fd);
	if (fd == -1)
		fd = 1;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = verif_param(str, i++, tab, fd);
			if (tmp <= -1)
				return (-1);
			val += tmp - 2;
		}
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(tab);
	return (val + i);
}
