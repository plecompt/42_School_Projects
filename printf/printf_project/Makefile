# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 11:38:32 by plecompt          #+#    #+#              #
#    Updated: 2017/04/03 11:38:34 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		NAME = libftprintf.a

		INC = ./includes/


		SRC = ./srcs/



		SRCS = ft_printf.c\
			ft_printf_conv_c.c\
			ft_printf_conv_d1.c\
			ft_printf_conv_d2.c\
			ft_printf_conv_o1.c\
			ft_printf_conv_o2.c\
			ft_printf_conv_p.c\
			ft_printf_conv_s.c\
			ft_printf_conv_u1.c\
			ft_printf_conv_u2.c\
			ft_printf_conv_unicode.c\
			ft_printf_conv_x1.c\
			ft_printf_conv_x2.c\
			ft_printf_conv_x3.c\
			ft_printf_conv_x4.c\
			ft_printf_flags1.c\
			ft_printf_flags2.c\
			ft_printf_format.c\
			ft_printf_init.c\
			ft_printf_no_conv.c\
			ft_printf_print1.c\
			ft_printf_print2.c\
			ft_printf_print3.c\
			ft_printf_spec.c\


		LIBFTS = srcs/ft_isascii.c\
			srcs/ft_memchr.c\
			srcs/ft_putchar.c\
			srcs/ft_putstr_fd.c\
			srcs/ft_strlcat.c\
			srcs/ft_strncpy.c\
			srcs/ft_strstr.c\
			srcs/ft_isdigit.c\
			srcs/ft_memcmp.c\
			srcs/ft_putchar_fd.c\
			srcs/ft_strcat.c\
			srcs/ft_strdup.c\
			srcs/ft_strlen.c\
			srcs/ft_nbrlen_base.c\
			srcs/ft_unbrlen_base.c\
			srcs/ft_atoi.c\
			srcs/ft_isprint.c\
			srcs/ft_memcpy.c\
			srcs/ft_strchr.c\
			srcs/ft_bzero.c\
			srcs/ft_putnbr.c\
			srcs/ft_putnbr_base.c\
			srcs/ft_putunbr_base.c\
			srcs/ft_strnstr.c\
			srcs/ft_tolower.c\
			srcs/ft_isalnum.c\
			srcs/ft_memmove.c\
			srcs/ft_putnbr_fd.c\
			srcs/ft_strcmp.c\
			srcs/ft_strncat.c\
			srcs/ft_strrchr.c\
			srcs/ft_toupper.c\
			srcs/ft_isalpha.c\
			srcs/ft_memccpy.c\
			srcs/ft_memset.c\
			srcs/ft_putstr.c\
			srcs/ft_strcpy.c\
			srcs/ft_strncmp.c\
			srcs/ft_memalloc.c\
			srcs/ft_memdel.c\
			srcs/ft_strnew.c\
			srcs/ft_strdel.c\
			srcs/ft_strclr.c\
			srcs/ft_striter.c\
			srcs/ft_striteri.c\
			srcs/ft_strmap.c\
			srcs/ft_strmapi.c\
			srcs/ft_strequ.c\
			srcs/ft_strnequ.c\
			srcs/ft_strsub.c\
			srcs/ft_strjoin.c\
			srcs/ft_strjoin_free.c\
			srcs/ft_strtrim.c\
			srcs/ft_putendl.c\
			srcs/ft_putendl_fd.c\
			srcs/ft_itoa.c\
			srcs/ft_strsplit.c\
			srcs/ft_lstnew.c\
			srcs/ft_lstdelone.c\
			srcs/ft_lstdel.c\
			srcs/ft_lstadd.c\
			srcs/ft_lstiter.c\
			srcs/ft_lstmap.c\
			srcs/ft_isprime.c\
			srcs/ft_isspace.c\
			srcs/ft_str_capitalize.c\
			srcs/ft_str_lowcase.c\
			srcs/ft_str_upcase.c\
			srcs/get_next_line.c\

LIBFT = ./libft/

SRCSS = $(addprefix $(SRC), $(SRCS))
LIBFTSS = $(addprefix ./libft/, $(LIBFTO))

SRCO = $(SRCS:.c=.o)
LIBFTO = $(LIBFTS:.c=.o)

all: $(NAME)


$(NAME):
	make -C $(LIBFT)
	gcc -Wall -Wextra -c -I $(INC) $(SRCSS)
	ar rc $(NAME) $(SRCO) $(LIBFTSS)
	ranlib $(NAME)
	rm -rf $(SRCO)

clean:
	rm -rf $(SRCO)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)


re: fclean all
