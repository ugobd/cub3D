/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:46:30 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/11 13:16:45 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (tmp1[i] == '\0' && tmp2[i] == '\0' && n == 1)
		return (0);
	while (tmp1[i] == tmp2[i] && i < n && tmp1[i] != '\0')
		i++;
	if (i >= n)
		return (0);
	return (tmp1[i] - tmp2[i]);
}
