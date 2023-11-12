/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:54:25 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/29 17:25:42 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putnb(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putnb(num / 16);
		ft_putnb(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_p(unsigned long long address)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (address == 0)
	{
		len += 1;
		write(1, "0", 1);
	}
	else
	{
		ft_putnb(address);
		len += ft_ptr_len(address);
	}
	return (len);
}
