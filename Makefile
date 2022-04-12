# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 20:05:24 by adaifi            #+#    #+#              #
#    Updated: 2022/04/12 22:45:07 by adaifi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = julia.c main.c mandelbrot.c clear_redraw.c hook.c
SRCDIR = src
OBJS_DIR = objs
CC = clang
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
NAME = fractol
LIB = libft.a
OBJS := $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
			@mkdir $@

$(OBJS_DIR)/%.o: $(SRCDIR)/%.c | $(OBJS_DIR)
			$(CC) -c $< -o $@

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME) $(LIB)

clean:
			@rm -rf $(OBJS_DIR)

fclean:	clean
			@rm -f  $(NAME)

re: fclean all

-include $(DEPS)

.PHONY:	clean re fclean all
