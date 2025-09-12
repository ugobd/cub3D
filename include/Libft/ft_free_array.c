/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:21:50 by thphilip          #+#    #+#             */
/*   Updated: 2025/03/27 14:12:05 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_array(void **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	free(strs);
}
