/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:57:41 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/29 16:47:35 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	abss(int n)
{
	if (n == -2147483648)
		return (2147483648);
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_initialize(int n, int i)
{
	char	*tmp;

	if (n < 0)
	{
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (0);
		tmp[0] = '-';
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (0);
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*tmp;

	i = ft_count_digits(n);
	tmp = ft_initialize(n, i);
	if (!tmp)
		return (0);
	tmp[i] = '\0';
	num = abss(n);
	while (num > 9)
	{
		tmp[--i] = (num % 10) + '0';
		num /= 10;
	}
	tmp[--i] = (num % 10) + '0';
	return (tmp);
}
/*
int	main(void)
{
	int number = -2147483648;
	int num2 = 0;
	int num3 = -2;
	char *str = ft_itoa(number);
	char *str2 = ft_itoa(num2);
	char *str3 = ft_itoa(num3);

	printf("Integer: %d\n", number);
	printf("String: %s\n", str);
	printf("Integer: %d\n", num2);
	printf("String: %s\n", str2);
	printf("Integer: %d\n", num3);
	printf("String: %s\n", str3);
	
	free(str);
	free(str2);
	free(str3);
	return (0);
}*/
