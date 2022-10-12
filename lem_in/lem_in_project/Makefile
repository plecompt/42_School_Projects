# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <plecompt@student.42.fr>              +#+  +:+       +#+     #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 10:58:54 by plecompt            #+#    #+#            #
#    Updated: 2016/12/09 15:51:37 by plecompt           ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME 		= lem-in

CC 	 		= clang
#CFLAGS 		= -Wall -Wextra -Werror

LIBS		=  -L libft/ -lft -lm

SRC_DIR		= srcs
INC_DIR 	= incs

SRCS  		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/error.c \
			  $(SRC_DIR)/error_util.c \
			  $(SRC_DIR)/list_file.c \
			  $(SRC_DIR)/util.c \
			  $(SRC_DIR)/dijkstra_init.c \
			  $(SRC_DIR)/dijkstra_res.c \
			  $(SRC_DIR)/ants.c \
			  $(SRC_DIR)/print.c \

OBJ  		= $(SRCS:%.c=%.o)
LIBFT 		= libft/libft.a

all: $(NAME)

$(LIBFT):
	@printf "Compiling libft ... "
	@make -C libft/
	@echo "Done"

$(NAME): $(OBJ) $(LIBFT)
	@printf "Compiling lem-in ... "
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "Done"

%.o: %.c
	@clear
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

norm :
	@make -C libft/ norm
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re
