# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 21:28:22 by rkamegne          #+#    #+#              #
#    Updated: 2019/03/17 12:37:19 by rkamegne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

SRC=srcs/ft_event_handling.c\
	srcs/main.c\
	srcs/ft_color_zoom.c\
	srcs/ft_mandelbrot.c\
	srcs/ft_fractal_init.c\
	srcs/ft_julia.c\
	srcs/ft_tricorn.c\
	srcs/ft_pthread.c\
	srcs/ft_palette.c\
	srcs/ft_burning_ship.c\

OBJECTS=$(SRC:.c=.o)
HEAD_LFT = libft/

Cflags = -Wall -Werror -Wextra

ifeq ($(shell uname -s), Linux)
		HEAD_MLX =../minilibx/
		HEAD_FRA = includes/
		LIBRARIES = -lm -L $(HEAD_MLX) -L $(HEAD_LFT) -lft -lmlx -lpthread
   		FRAMEWORKS = -lXext -lX11
else
		HEAD_MLX =minilibx_macos/
		HEAD_FRA = includes/
		LIBRARIES = -L minilibx_macos -lmlx -L libft -lft -lpthread
    	FRAMEWORKS=-framework OpenGl -framework Appkit
endif

all: $(NAME)

$(NAME):
	@make -C $(HEAD_LFT)
	@make -C $(HEAD_MLX)
	gcc $(Cflags) -I $(HEAD_LFT) -I $(HEAD_FRA) -I $(HEAD_MLX) -o $(NAME) $(SRC) $(LIBRARIES) $(FRAMEWORKS)
	@echo "\033[32m[ ✔ ] \033[32mCreate Fractol \033[0m"

clean:
	@make clean -C $(HEAD_LFT)
	@make clean -C $(HEAD_MLX)
	/bin/rm -f $(OBJECTS)
	@echo "\033[32m[ ✔ ] \033[32mCleaning .o files \033[0m"

fclean: clean
	@make fclean -C $(HEAD_LFT)
	/bin/rm -f $(NAME)
	@echo "\033[32m[ ✔ ] \033[32mCleaning executable \033[0m"

re: fclean all

.PHONY : fclean clean all re
