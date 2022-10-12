#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <plecompt@student.42.fr           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/19 11:53:53 by plecompt          #+#    #+#              #
#    Updated: 2016/04/15 18:40:58 by plecompt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_NAME = calculs.c check.c core.c algo.c parse.c utility.c mallocs.c struct.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft
NAME_LIB = libft.a

SRC_PATH = ./src/
OBJ_PATH = ./obj/

LIB_PATH = ./libft/
INC_PATH = ./include/ $(LIB_PATH)

SRC      = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ      = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC      = $(addprefix -I, $(INC_PATH))
LIB      = $(addprefix -L, $(LIB_PATH))

NAME     = fillit
CC       = gcc

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lft

all: libft $(NAME)

.PHONY: libft clean fclean re

libft :
	make -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LDFLAGS) -o $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	@$(RM) -v $(OBJ)
	@$(RM) -rv $(OBJ_PATH)
	make -C $(LIB_PATH) clean

fclean : clean
	@$(RM) -v $(NAME)
	@$(RM) -v $(LIB_PATH)$(NAME_LIB)

re: fclean all
