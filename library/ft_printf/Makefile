# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 12:52:51 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/12 12:17:59 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

CFLAGS	=	-Werror -Wall -Wextra -Iinclude

NAME	=	libftprintf.a

SRCS	=	ft_itoa.c ft_print_c.c ft_print_d_i.c ft_print_p.c ft_print_s.c ft_print_u.c \
			ft_print_x.c ft_printf.c ft_putchar_fd.c ft_strlen.c

OBJS	=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
