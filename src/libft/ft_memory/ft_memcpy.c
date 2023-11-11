/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:21:16 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/08 13:19:55 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *dst = "ello" *src = "hello"
void	*ft_memcpy(void *dst, const void *src, t_size_t n)
{
	t_size_t		i;
	unsigned char	*dest;
	unsigned char	*srcc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = srcc[i];
		i++;
	}
	return (dst);
}
// It is also work : ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
