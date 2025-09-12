/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:31:17 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/12 11:38:12 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i] != 0)
		i++;
	if (c == set[i])
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (char_check(s1[start], set))
		start++;
	while (char_check(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
