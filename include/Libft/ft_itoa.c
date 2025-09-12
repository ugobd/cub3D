/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:11 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/11 14:49:06 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = n;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = malloc(sizeof(char) * (find_size(n) + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[find_size(n)] = '\0';
	i = find_size(n) - 1;
	if (n < 0)
	{
		tmp[0] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		tmp[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	tmp[i] = n + 48;
	return (tmp);
}
