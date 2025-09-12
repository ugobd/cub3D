/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:21 by thphilip          #+#    #+#             */
/*   Updated: 2025/04/08 12:08:34 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	size_t	i;

	if (ft_strlen(s) > n)
		dest = ft_calloc(sizeof(char), (n + 1));
	else
		dest = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
