# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 10:21:33 by ktiyari           #+#    #+#              #
#    Updated: 2023/12/29 10:21:37 by ktiyari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

SRC = ft_printf.c print_char.c print_str.c print_nb.c print_unsigned.c\
	print_hex.c print_ptr.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

.o: .c
	$(CC) $(CFLAGS) -c $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all