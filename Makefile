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
	gcc $(Cflags) -I $(HEAD_LFT) -I $(HEAD_FRA) -I $(HEAD_MLX) -o $(NAME) $(SRC) $(LIBRARIES) $(FRAMEWORKS)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"

clean:
	@make clean -C $(HEAD_LFT)
	/bin/rm -f $(OBJECTS)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaning .o files"

fclean: clean
	@make fclean -C $(HEAD_LFT)
	/bin/rm -f $(NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaning executable"

re: fclean all

.PHONY : fclean clean all re
