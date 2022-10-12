# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hivian <hivian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 09:17:14 by hivian            #+#    #+#              #
#    Updated: 2017/05/15 12:44:25 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM 	= asm
NAME_VM		= corewar

FT_PRINTF_H		= libft/include/ft_printf.h
LIBFT_H			= libft/include/libft.h
ASM_H			= ./incs/asm.h
VM_H			= ./incs/vm.h
OP_H			= ./incs/op.h

C_DIR_ASM 	= srcs_asm
C_DIR_LIBFT = ./libft/srcs/
O_DIR_ASM 	= objdir_asm

C_DIR_VM 	= srcs_vm
O_DIR_VM 	= objdir_vm

CC 	 		= clang -Wall -Wextra -Werror
HEAD		= -Iincs/

C_FILES_ASM = $(shell find $(C_DIR_ASM) -type f -print | grep "\.c")
C_FILES_VM = $(shell find $(C_DIR_VM) -type f -print | grep "\.c")
C_FILES_LIBFT = $(shell find $(C_DIR_LIBFT) -type f -print | grep "\.c")

compteur_asm = 1
result_asm = 0
COUNT_ASM = $(shell ls $(C_DIR_ASM) | grep "\.c" | wc -l)
COUNT_2_ASM = $(strip $(COUNT_ASM))
pourcent_asm = $(shell echo "scale=4; 100 / $(COUNT_2_ASM)" | bc  )

compteur_vm = 1
result_vm = 0
COUNT_VM = $(shell ls $(C_DIR_VM) | grep "\.c" | wc -l)
COUNT_2_VM = $(strip $(COUNT_VM))
pourcent_vm = $(shell echo "scale=4; 100 / $(COUNT_2_VM)" | bc  )

O_DIRS_ASM 		= $(C_DIR_ASM:$(C_DIR_ASM)/%=$(O_DIR_ASM)/%)
O_FILES_ASM		= $(C_FILES_ASM:$(C_DIR_ASM)/%.c=$(O_DIR_ASM)/%.o)

O_DIRS_VM 		= $(C_DIR_VM:$(C_DIR_VM)/%=$(O_DIR_VM)/%)
O_FILES_VM		= $(C_FILES_VM:$(C_DIR_VM)/%.c=$(O_DIR_VM)/%.o)


LIBFT 		= libft/libft.a

all: $(NAME_ASM) $(NAME_VM)

$(NAME_ASM): $(LIBFT) $(O_FILES_ASM) $(ASM_H)
	clear
	@echo "Compiling asm ..."
	@echo "100%"
	@$(CC) $(CFLAGS) -o $(NAME_ASM) $(O_FILES_ASM) $(LIBFT)
	@echo "Done"

$(O_DIR_ASM)/%.o: $(C_DIR_ASM)/%.c
	@mkdir -p $(O_DIRS_ASM) $(O_DIR_ASM)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)
	@clear
	@echo "Compiling asm ..."
	@echo "$(result_asm)%"
	$(eval compteur_asm=$(shell echo $$(($(compteur_asm) + 1))))
	$(eval result_asm=$(shell echo "scale=4; $(compteur_asm) * $(pourcent_asm)" | bc -l))

$(NAME_VM):  $(LIBFT) $(O_FILES_VM) $(VM_H) $(OP_H)
	clear
	@echo "Compiling vm ..."
	@echo "100%"
	@$(CC) $(CFLAGS) -o $(NAME_VM) $(O_FILES_VM) $(LIBFT)
	@echo "Done"

$(O_DIR_VM)/%.o: $(C_DIR_VM)/%.c
	@mkdir -p $(O_DIRS_VM) $(O_DIR_VM)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)
	@clear
	@echo "Compiling vm ..."
	@echo "$(result_vm)%"
	$(eval compteur_vm=$(shell echo $$(($(compteur_vm) + 1))))
	$(eval result_vm=$(shell echo "scale=4; $(compteur_vm) * $(pourcent_vm)" | bc -l))

$(LIBFT): $(C_FILES_LIBFT) $(LIBFT_H) $(FT_PRINTF_H)
	@make -C libft/
	@sleep 1

clean:
	@rm -rf $(O_DIR_ASM)
	@rm -rf $(O_DIR_VM)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME_ASM)
	@rm -f $(NAME_VM)
	@make fclean -C libft/


re: fclean all

.PHONY: all clean fclean re
