/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:42:42 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/14 10:55:54 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	find_size(char const *str, char sep, int pos)
{
	int	i;

	i = pos;
	while (str[i] != sep && str[i])
		i++;
	return (i - pos);
}

static char	**super_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs[i]);
	free(strs);
	return (NULL);
}

static char	**set_start(char const *str, char c, int *i, int *j)
{
	char	**strs;

	if (!str)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (strs == NULL)
		return (NULL);
	*i = 0;
	*j = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	strs = set_start(s, c, &i, &j);
	if (strs == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			strs[j] = malloc(sizeof(char) * (find_size(s, c, i) + 1));
			if (strs[j] == NULL)
				return (super_free(strs));
			while (s[i] != c && s[i])
				strs[j][k++] = s[i++];
			strs[j++][k] = '\0';
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
