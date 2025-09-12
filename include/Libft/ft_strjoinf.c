/* ************************************************************************** */
/*	                                                                     */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:19:13 by thphilip          #+#    #+#             */
/*   Updated: 2025/04/09 13:51:11 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2)
{
	char	*tab;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (s2);
	if (!s2 && s1)
		return (s1);
	tab = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tab);
}
