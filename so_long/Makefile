# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 03:58:47 by fchanane          #+#    #+#              #
#    Updated: 2022/06/24 02:15:24 by fchanane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS	= so_long.h

NAME	=	so_long

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

RM		=	rm -f

SRC = 	draw.c\
		map_check.c\
		errors_msg.c\
		first_check.c\
		get_next_line.c\
		get_next_line_utils.c\
		libft.c\
		libft2.c\
		map_structure.c\
		moves.c\
		parser.c\
		parsing_error_msg.c\
		so_long.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o : %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all