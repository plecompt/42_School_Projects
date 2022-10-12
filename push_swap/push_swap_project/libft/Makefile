# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 15:36:53 by plecompt          #+#    #+#              #
#    Updated: 2017/05/06 16:35:43 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/

H_FILE			= ./includes/libft.h

SRC_NAME = ft_memalloc.c ft_strcat.c ft_strncmp.c \
	   ft_memccpy.c ft_strchr.c ft_strncpy.c \
	   ft_atoi.c ft_memchr.c ft_strclr.c ft_strnequ.c \
	   ft_bzero.c ft_memcmp.c ft_strcmp.c ft_strnew.c \
	   ft_isalnum.c ft_memcpy.c ft_strcpy.c ft_strnstr.c \
	   ft_isalpha.c ft_memdel.c ft_strdel.c ft_strrchr.c \
	   ft_isascii.c ft_memmove.c ft_strdup.c ft_strsplit.c \
	   ft_isdigit.c ft_memset.c ft_strequ.c ft_strstr.c \
	   ft_isprint.c ft_putchar.c ft_striter.c ft_strsub.c \
	   ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_strtrim.c \
	   ft_lstadd.c ft_putendl.c ft_strjoin.c ft_tolower.c \
	   ft_lstdel.c ft_putendl_fd.c ft_strlcat.c ft_toupper.c \
	   ft_lstdelone.c ft_putnbr.c ft_strlen.c \
	   ft_lstiter.c ft_putnbr_fd.c ft_strmap.c \
	   ft_lstmap.c ft_putstr.c ft_strmapi.c \
	   ft_lstnew.c ft_putstr_fd.c ft_strncat.c ft_atoi_base.c \
	   ft_putnbr_base.c \
	   ft_lstreverse.c ft_convert_decitooctal.c ft_itoa_base.c \
	   ft_strnjoin.c ft_strndup.c ft_itoa_0x.c ft_del.c \
	   ft_int_size.c ft_itoa_ll.c ft_itoa_l.c ft_itoa_ul.c \
	   ft_itoa_ull.c ft_itoa_u.c ft_itoa_base_ll.c ft_itoa_base_uint.c \
	   ft_itoa_ul.c ft_itoa_base_l.c ft_itoa_base_ul.c ft_itoa_base_ull.c \
	   ft_itoa_hh.c ft_itoa_h.c ft_itoa_base_h.c ft_itoa_base_hh.c \
	   ft_strchr_base.c ft_strwlen.c ft_int_size.c ft_strjoin_free.c \
	   print_bits.c ft_wcrtomb.c ft_itoa_ulong.c ft_itoa_base_uh.c ft_itoa_uh.c \
	   ft_itoa_base_uhh.c ft_itoa_uhh.c ft_putnstr.c \
	   ft_strjoin_size.c ft_strcut.c get_next_line.c ft_lststrsplit.c \
	   ft_putbuf.c ft_lstatoisplit.c \
	   ft_is_sort.c ft_list_is_sort.c ft_list_size.c ft_putnbuf.c ft_cpychar.c \
	   ft_list_find.c ft_list_find_less.c ft_list_find_more.c ft_lst_not_sort.c \
	   ft_count_less.c ft_insertion_sort.c ft_quick_sort.c ft_str_is_only_digit.c ft_atol.c\

OBJ_PATH = ./obj/

CPPFLAGS = -Iincludes

NAME = libft.a

CC = clang

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) $(H_FILE)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all
