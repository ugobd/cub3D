/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:28:23 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/14 15:23:25 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen((const char *)dst);
	j = 0;
	k = ft_strlen((const char *)dst);
	l = ft_strlen(src);
	if (size <= k)
		return (l + size);
	while (src[j] && j < size - k - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + l);
}
