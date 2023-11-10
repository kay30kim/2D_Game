/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:21:18 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:43:43 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*srcc;

	if (!dst || !src)
		return (NULL);
	dest = (char *)dst;
	srcc = (char *)src;
	if (dst == src)
		return (dst);
	if (srcc < dest && dest < srcc + len)
	{
		while (len--)
			dest[len] = srcc[len];
	}
	else
	{
		while (len--)
			*dest++ = *srcc++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[30] = "Hello, World!";
	char src2[30] = "";
	printf("%s\n", ft_memmove(0, 0, 0));
	printf("%s\n", memmove(0, 0, 0));
	printf("%s\n", ft_memmove(src+6, src2, 0));
	printf("%s\n", memmove(src+6, src2, 0));
	printf("%s\n", ft_memmove(src, src, 5));
	printf("%s\n", memmove(src, src, 5));
	return (0);
}*/
// dst = 0,src = 0 , len = 0 should not be care..
/* 
if (dst == src)
		return (dst); -> ho,,,
*/
// unsigned char* (x) char * (o)
