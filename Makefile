# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:17:03 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/07 13:07:50 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
NAME	=	so_long
VPATH	=	$(SRC_DIR)
#// /Users/kyung-ki/.brew/lib
MLX		=	-framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/kyung-ki/.brew/lib"

SRC_DIR	=	src
SRCS	=	main.c
#OBJS	=	$(SRCS:.c=.o)
MK		=	mkdir -p
BIN_DIR =	bin
BIN		=	$(addprefix $(BIN_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR=  include
MLXINCLUDE = MLX42/include



$(BIN_DIR)/%.o	: %.c
	$(CC) $(CFLAGS) $(MLX) -c $< -o $@

all : $(NAME)

$(NAME) : $(BIN_DIR) $(BIN)
	$(CC) $(CFLAGS) $(BIN) $(MLX) -o $(NAME)
#	$(CC) $(CFLAGS) -Iinclude -I./ $(MLX) $(NAME) $(BIN) src/main.c


$(BIN_DIR) :
	$(MK) $(BIN_DIR)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
