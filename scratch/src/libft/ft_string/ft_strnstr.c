/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:21:37 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:45:42 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack)
		return (NULL);
	if (!needle || needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (i + j < len && haystack[i + j]
				&& needle[j] && haystack[i + j] == needle[j])
			{
				j++;
			}
			if (ft_strlen(needle) == j)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
