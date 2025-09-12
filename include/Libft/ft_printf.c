/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:32:11 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/23 11:01:02 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_conversion(const char str, va_list tab)
{
	int	val;

	if (str == 'c')
		val = ft_putchar(va_arg(tab, int));
	else if (str == 's')
		val = ft_putstr(va_arg(tab, char *));
	else if (str == 'p')
		val = ft_putpointer(va_arg(tab, unsigned long));
	else if (str == 'd' || str == 'i')
		val = ft_putnbrdec(va_arg(tab, int));
	else if (str == 'u')
		val = ft_putnbruns(va_arg(tab, unsigned int));
	else if (str == 'x' || str == 'X')
		val = ft_putnbrhex(va_arg(tab, unsigned int), str);
	else if (str == '%')
		val = ft_putchar('%');
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

static int	verif_param(const char *str, int i, va_list tab)
{
	int	tmp;

	tmp = get_conversion(str[i + 1], tab);
	if (tmp == -3 && str[i + 1])
	{
		ft_putchar(str[i]);
		ft_putchar(str[i + 1]);
		return (2);
	}
	else if (tmp == -3 && !str[i + 1])
		return (-1);
	else if (tmp == -1)
		return (ft_putstr("(null)"));
	else if (tmp == -2)
		return (ft_putstr("(nil)"));
	else
		return (tmp);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		val;
	int		tmp;
	va_list	tab;

	if (def_start(str, &i, &val) == -1)
		return (-1);
	va_start(tab, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = verif_param(str, i, tab);
			if (tmp <= -1)
				return (-1);
			val += tmp - 2;
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(tab);
	return (val + i);
}
