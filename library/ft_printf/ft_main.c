/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:45:09 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/12 16:22:25 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int				i;
	unsigned int	n;

	i = 10;
	n = -3;
	printf("[%c]Name : %s, age : %d, address : %p\n", 'A', "kay", i, &i);
	ft_printf("[%W]Name : %s, age : %d, address : %p\n", 'A', "kay", 10, &i);
	printf("unsigned num = %u, hex = %x, %X  check percent %%\n", n, i, i);
	ft_printf("unsigned num = %u, hex = %x, %X  check percent %%\n", n, i, i);
	printf("%c %s %d %p %u %x %X\n", 0, NULL, 0, NULL, 0, 0, 0);
	ft_printf("%c %s %d %p %u %x %X\n", 0, NULL, 0, NULL, 0, 0, 0);
	return (0);
}
