/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:26:26 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/11 11:30:50 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sourc;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	sourc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = sourc[i];
		i++;
	}
	return (dest);
}
