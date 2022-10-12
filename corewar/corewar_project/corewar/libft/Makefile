# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:17:01 by jsivanes          #+#    #+#              #
#    Updated: 2017/04/28 15:55:45 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

HEAD 	= -Iinclude/
INC		= ./include/libft.h
INC2	=	./include/ft_printf.h
C_DIR = srcs
O_DIR = objdir

compteur = 1
result = 0

FLAGS = -Wall -Wextra -Werror

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

COUNT = $(shell ls -R $(C_DIR) | grep "\.c" | wc -l)
COUNTE = $(strip $(COUNT))
pour = $(shell echo "scale=4; 100 / $(COUNTE)" | bc  )

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES= $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

all: $(NAME)

$(NAME): $(O_FILES) $(INC) $(INC2)
	@clear
	@echo "Compiling libft ..."
	@echo "100%"
	@ar rc $@ $^
	@ranlib $@
	@echo "Done"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)
	@clear
	@echo "Compiling libft ... "
	@echo "$(result)%"
	$(eval compteur=$(shell echo $$(($(compteur) + 1))))
	$(eval result=$(shell echo "scale=4; $(compteur) * $(pour)" | bc -l))

.PHONY: clean fclean re

clean:
	@rm -rf $(O_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
