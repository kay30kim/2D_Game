/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:30:06 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/25 16:20:30 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	if (!s1)
		return (0);
	tmp = (char *)malloc(ft_strlen(s1) + 1);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < ft_strlen(s1))
		tmp[i] = s1[i];
	tmp[i] = '\0';
	return (tmp);
}
