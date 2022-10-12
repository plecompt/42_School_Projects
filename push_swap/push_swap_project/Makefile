# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 09:17:14 by plecompt          #+#    #+#              #
#    Updated: 2017/05/08 14:45:38 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH 	= push_swap
NAME_CHECK	= checker

H_FILE		= ./includes/push_swap.h
H_LIBFT		= ./libft/includes/libft.h

C_DIR_LIBFT = ./libft/srcs/

C_DIR_PUSH 	= srcs_pushswap
O_DIR_PUSH 	= objdir_push

C_DIR_CHECK 	= srcs_checker
O_DIR_CHECK 	= objdir_checker

CC 	 		= clang -Wall -Wextra -Werror
HEAD		= -Iincludes/

C_FILES_PUSH = $(shell find $(C_DIR_PUSH) -type f -print | grep "\.c")
C_FILES_CHECK = $(shell find $(C_DIR_CHECK) -type f -print | grep "\.c")
C_FILES_LIBFT = $(shell find $(C_DIR_LIBFT) -type f -print | grep "\.c")

compteur_push = 1
result_push = 0
COUNT_PUSH = $(shell ls $(C_DIR_PUSH) | grep "\.c" | wc -l)
COUNT_2_PUSH = $(strip $(COUNT_PUSH))
pourcent_push = $(shell echo "scale=4; 100 / $(COUNT_2_PUSH)" | bc  )

compteur_check = 1
result_check = 0
COUNT_CHECK = $(shell ls $(C_DIR_CHECK) | grep "\.c" | wc -l)
COUNT_2_CHECK = $(strip $(COUNT_CHECK))
pourcent_check = $(shell echo "scale=4; 100 / $(COUNT_2_CHECK)" | bc  )

O_DIRS_PUSH 		= $(C_DIR_PUSH:$(C_DIR_PUSH)/%=$(O_DIR_PUSH)/%)
O_FILES_PUSH		= $(C_FILES_PUSH:$(C_DIR_PUSH)/%.c=$(O_DIR_PUSH)/%.o)

O_DIRS_CHECK 		= $(C_DIR_CHECK:$(C_DIR_CHECK)/%=$(O_DIR_CHECK)/%)
O_FILES_CHECK		= $(C_FILES_CHECK:$(C_DIR_CHECK)/%.c=$(O_DIR_CHECK)/%.o)


LIBFT 		= libft/libft.a

all: $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH): $(LIBFT) $(O_FILES_PUSH) $(H_FILE)
	clear
	@echo "Compiling push_swap ..."
	@echo "100%"
	@$(CC) $(CFLAGS) -o $(NAME_PUSH) $(O_FILES_PUSH) $(LIBFT)
	@echo "Done"

$(O_DIR_PUSH)/%.o: $(C_DIR_PUSH)/%.c
	@mkdir -p $(O_DIRS_PUSH) $(O_DIR_PUSH)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)
	@clear
	@echo "Compiling push_swap ..."
	@echo "$(result_push)%"
	$(eval compteur_push=$(shell echo $$(($(compteur_push) + 1))))
	$(eval result_push=$(shell echo "scale=4; $(compteur_push) * $(pourcent_push)" | bc -l))

$(NAME_CHECK): $(LIBFT) $(O_FILES_CHECK) $(H_FILE)
	clear
	@echo "Compiling checker ..."
	@echo "100%"
	@$(CC) $(CFLAGS) -o $(NAME_CHECK) $(O_FILES_CHECK) $(LIBFT)
	@echo "Done"

$(O_DIR_CHECK)/%.o: $(C_DIR_CHECK)/%.c
	@mkdir -p $(O_DIRS_CHECK) $(O_DIR_CHECK)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)
	@clear
	@echo "Compiling checker ..."
	@echo "$(result_check)%"
	$(eval compteur_check=$(shell echo $$(($(compteur_check) + 1))))
	$(eval result_check=$(shell echo "scale=4; $(compteur_check) * $(pourcent_check)" | bc -l))

$(LIBFT): $(C_FILES_LIBFT) $(H_LIBFT)
	@make -C libft/
	@sleep 1

clean:
	@rm -rf $(O_DIR_PUSH)
	@rm -rf $(O_DIR_CHECK)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME_PUSH)
	@rm -f $(NAME_CHECK)
	@make fclean -C libft/


re: fclean all

.PHONY: all clean fclean re
