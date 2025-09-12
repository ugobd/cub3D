/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:45:20 by thphilip          #+#    #+#             */
/*   Updated: 2024/10/14 11:08:36 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if ((long)nmemb < 0 || (long)size < 0)
		return (malloc(1));
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	if (!alloc)
		return (alloc);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
