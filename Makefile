# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 21:28:22 by rkamegne          #+#    #+#              #
#    Updated: 2019/03/11 21:28:24 by rkamegne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

SRC=srcs/ft_event_handling.c\
	srcs/main.c\
	srcs/ft_color_zoom.c\
	srcs/ft_mandelbrot.c\
	srcs/ft_opti.c\
	srcs/ft_fractal_init.c\

OBJECTS=$(SRC:.c=.o)

Cflags = -Wall -Werror -Wextra

ifeq ($(shell uname -s), Linux)
		HEADERS = includes/fractol.h minilibx/mlx.h
		LIBRARIES = -L minilibx -lmlx -L libft -lft
   		FRAMEWORKS = -Xext -X11
else
		HEADERS = includes/fractol.h minilibx_macos/mlx.h
		LIBRARIES = -L minilibx_macos -lmlx -L libft -lft
    	FRAMEWORKS=-framework OpenGl -framework Appkit
endif

all: $(NAME)

$(NAME):
	#Compiling
	gcc $(Cflags) -o $(NAME) $(SRC) $(LIBRARIES) $(FRAMEWORKS)

clean:
	#Cleaning
	/bin/rm -f $(OBJECTS)

fclean: clean
	#Fcleaning
	/bin/rm -f $(NAME)

re: fclean all

PHONY : fclean clean all re
