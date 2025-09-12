/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:26:40 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/11 10:39:49 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)s;
	while (i < n)
	{
		if (tab[i] == (unsigned char) c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}
