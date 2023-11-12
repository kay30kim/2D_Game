/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:08:54 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/12 12:19:22 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

char	*ft_itoa(int n);
int		ft_print_c(char c);
int		ft_printstr(char *str);
int		ft_print_d_i(int num);
int		ft_ptr_len(unsigned long long num);
void	ft_putnb(unsigned long long num);
int		ft_print_p(unsigned long long address);
int		ft_print_s(char *str);
char	*ft_uitoa(unsigned int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int num, char c);
int		ft_print_percent(void);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);

#endif