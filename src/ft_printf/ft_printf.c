/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:56:31 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/29 17:52:24 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (format == 's')
		len += ft_print_s(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_p(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_print_d_i(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(ap, str[i + 1]);
			i++;
		}
		else
		{
			len += 1;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
