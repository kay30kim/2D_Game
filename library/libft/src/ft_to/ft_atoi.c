/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:53 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/25 14:44:30 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pass(const char *str, int *i, int *sign)
{
	while (str[*i] && ((9 <= str[*i] && str[*i] <= 13) || str[*i] == 32))
	{
		*i = *i + 1;
	}
	if (str[*i] != '\0' && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!str)
		return (0);
	ft_pass(str, &i, &sign);
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * (int)num);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char str1[] = "++2147483647";
	char str2[] = " 2147483648";
	char str3[] = "  -2147483648";
	char str4[] = "-2147483649";
	char str5[] = "2200000000";
	char str6[] = "";
	char str7[] = "+1";
	printf("%d %d\n", ft_atoi(str1), atoi(str1));
	printf("%d %d\n", ft_atoi(str2), atoi(str2));
	printf("%d %d\n", ft_atoi(str3), atoi(str3));
	printf("%d %d\n", ft_atoi(str4), atoi(str4));
	printf("%d %d\n", ft_atoi(str5), atoi(str5));
	printf("%d %d\n", ft_atoi(str6), atoi(str6));
	printf("%d %d\n", ft_atoi(str7), atoi(str7));
	return (0);
}*/
