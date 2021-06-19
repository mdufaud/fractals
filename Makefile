# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 14:59:24 by mdufaud           #+#    #+#              #
#    Updated: 2016/01/04 18:01:25 by mdufaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname)

ifeq ($(OS),Linux)
MLIBX = -L /etc/X11/lib -L minilibx -lmlx -lX11 -lXext
IMLIBX = -I minilibx
MLX = minilibx/libmlx.a
MKMLX = make -C minilibx
SHELL := /bin/bash
ECHO := echo -e
else
MLIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
IMLIBX = -I minilibx_macos
MLX = minilibx_macos/libmlx.a
MKMLX = make -C minilibx_macos
SHELL := /bin/sh
ECHO := echo
endif

NAME = fractol
CFLAGS = gcc -Wall -Wextra -Werror
OFLAGS = -I libft/includes/. -I ./includes/.
LFLAGS = -L libft -lft -lm
LIB = libft/libft.a
MKLIB = make -C libft
PATH_SRC = src
PATH_OBJ = obj
SRC = main.c\
	  hook.c\
	  create_img.c\
	  destroy_img.c\
	  phoenix.c\
	  init.c\
	  mlx.c\
	  error.c\
	  put_pixel.c\
	  free.c\
	  print.c\
	  swap.c\
	  rand.c\
	  julia.c\
	  colors.c\
	  keys.c\
	  fractol_origin.c\
	  parse.c\
	  rotate.c\
	  draw_by_pixels.c\
	  draw_by_iter.c\
	  newton.c\
	  newton_1.c\
	  newton_2.c\
	  newton_3.c\
	  palette2.c\
	  burning_ship.c\
	  complexe.c\
	  tricorn.c\
	  triangle.c\
	  draw_line.c\
	  popcorn.c\
	  mandelbrot.c

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

INCLUDES = includes/fractol.h\
		   includes/mlx.h\
		   includes/key_code.h

all : $(NAME)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@mkdir -p $(PATH_OBJ)
	@$(CFLAGS) $(OFLAGS) $(IMLIBX) -o $@ -c $<

$(LIB) :
	@$(MKLIB)

$(MLX):
	@$(MKMLX)

$(NAME) : $(LIB) $(MLX) $(OBJ)
	@$(ECHO) "\033[32m[ $(NAME) objects done ]\033[00m"
	@$(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS) $(MLIBX)
	@$(ECHO) "\033[32m[ $(NAME) compiled ]\033[00m"

lib : $(LIB) $(NAME)
	@$(ECHO) "\033[32m[ Library done && $(NAME) compiled ]\033[00m"

clean :
	@$(MKLIB) clean
	@$(MKMLX) clean
	@rm -f $(OBJ)
	@$(ECHO) "\033[31m[ $(NAME) : objects deleted ]\033[00m"

fclean : clean
	@$(MKLIB) fclean
	@rm -f $(NAME)
	@$(ECHO) "\033[31m[ $(NAME) : ./$(NAME) deleted ]\033[00m"

re : fclean all

.PHONY : fclean re clean all lib
