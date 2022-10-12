# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 20:18:54 by plecompt          #+#    #+#              #
#    Updated: 2015/03/16 14:02:02 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = gcc -o

SRC =	fdf.c  \
		get_next_line.c \
		ft_getnbr.c \
		calcul.c \
		color.c \
		print.c \

FLAGS = -Wall -Wextra -Werror -O3

OBJECT = $(SRC:.c=.o)
	COMP = gcc -c
	NAME = fdf

all : $(NAME)

$(NAME) : $(OBJECT)
	@$(MKEX) $(NAME) $(OBJECT) -L /usr/X11/lib -lmlx -lXext -lX11 -L libft/ -lft
	@echo "FDF a bien ete compile"

$(OBJECT) :
	@make -C libft/
	@$(COMP) $(SRC) $(FLAGS) -I./ -I /usr/X11/include/ -I libft/
	@echo "Compilation des fichiers C de FdF"

clean :
	@/bin/rm -f $(OBJECT)
	@make clean -C libft/
	@echo "Objets de fdf supprimes"


fclean : clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "Dossier fdf nettoye"

re : fclean all
