# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/08/08 20:49:18 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
PFLAGS			= -lpthread
FLAGS			= $(CFLAGS) $(PFLAGS)

FILES			= main.c key_commands.c fractals.c color.c draw_fractal.c mouse_commands.c

SRC				= $(addprefix srcs/, $(FILES))
OBJ				= $(addprefix build/, $(FILES:.c=.o))

FRAMEWORKS		= -framework OpenGL -framework AppKit

INC_MINILIBX	= -I minilibx
LINK_MINILIBX	= -L minilibx -lmlx
MINILIBX		= $(INC_MINILIBX) $(LINK_MINILIBX)

INC_LIBGFX		= -I libgfx
LINK_LIBGFX		= -L libgfx -lgfx
GFX				= $(INC_LIBMLX) $(LINK_LIBGFX)

INC_LIBFT		= -I libft
LINK_LIBFT		= -L libft -lft
FT				= $(INC_LIBFT) $(LINK_LIBFT)

all: $(NAME)

libft/libft.a:
	make -C libft re

libgfx/libgfx.a:
	make -C libgfx re

minilibx/libmlx.a:
	make -C minilibx re

$(NAME): libft/libft.a libgfx/libgfx.a minilibx/libmlx.a $(OBJ)
	@$(CC) $(FLAGS) $(MINILIBX) $(GFX) $(FT) -I includes $(FRAMEWORKS) $(OBJ) -o $@
	@echo "Execute with ./$@ (fractal name)"
	@echo "Fractals: mandelbrot, julia, bship"

build:
	mkdir build

build/%.o: srcs/%.c | build
	@echo "Building $@"
	@$(CC) $(INC_LIBFT) $(INC_LIBGFX) $(INC_MINILIBX) -I includes -c $< -o $@

clean:
	@rm -fr build

fclean: clean
	@rm -f $(NAME)

re: fclean all
