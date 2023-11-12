/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:19 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/29 17:27:40 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*tmp;
	int		len;

	len = ft_numlen(n);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (len--)
	{
		tmp[len] = n % 10 + '0';
		n /= 10;
	}
	return (tmp);
}

int	ft_print_u(unsigned int n)
{
	int		len;
	char	*str_num;

	len = 1;
	if (n == 0)
		write(1, "0", 1);
	else
	{
		str_num = ft_uitoa(n);
		len = ft_printstr(str_num);
		free(str_num);
	}
	return (len);
}
