# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plecompt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/04 11:53:42 by plecompt          #+#    #+#              #
#    Updated: 2016/10/04 11:53:44 by plecompt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol
CC 	 		= gcc

CFLAGS		= -Wall -Wextra -Werror -g3

LIBS		=  -L libft/ -lft -lmlx -framework OpenGl -framework Appkit

SRC  		= main.c \
				ft_init.c \
				julia.c \
				mandelbrot.c \
				tree.c \
				tree_hook.c \
				color_julia.c \
				color_mandelbrot.c \
				loop.c \
				debug.c

OBJ  		= $(SRC:%.c=objs/%.o)


SRC_DIR 	= ./srcs/
INCLUDE_DIR = -I ./includes/ -I libft/

all: objs $(NAME)

objs:
	@mkdir objs

$(NAME): $(OBJ)
	@echo "\n"
	@echo "                       	      ~   .ueu.u11111111Wu."
	@echo "                                .111111111111111111Wu"
	@echo "                                :111111111111111111111Wu."
	@echo "                                1111111111111111111111111W."
	@echo "                                 11111111111111111111*11111T"
	@echo "                                 11111111111111111*@~ ~@111~"
	@echo "                                :11111111111111111~    :11^"
	@echo "                                 *11111111111111*~~~:   1+"
	@echo "                                  11111@%@1111^ :~.:uu~~1"
	@echo "                                  11111! ~@11~    (UU@!i*"
	@echo "                                 11111@! ::!~     @@T*!11"
	@echo "                                 **111!~!**           !~^~"
	@echo "                                   11TH  !:            1"
	@echo "                                   1*?~   ~         ~+Xi"
	@echo "                                  !1~~    !         :W^*"
	@echo "                                  1?      !W.      @1~v"
	@echo "                                 !1   :   ~11i.    !T"
	@echo "                                 W!   ~    1^T^*ou:1!"
	@echo "                             . :*^         ~ ~   **^^~+:.."
	@echo "                         ..Ue@^*             ~           \\"
	@echo "                      .W11RMMM                            @."
	@echo "                     :1MMMMMM8                            ~!"
	@echo "                    .1MMMMMMMR!                           ~!"
	@echo "                    W1MMMMMMMM8                           !!"
	@echo "                   :1RMMMMMMM@RX                  .      ~~1"
	@echo "                   WRMM8MMMMMM11:                 !       ~T"
	@echo "                   1MM11MM1MMM111:               !~       ~W"
	@echo "                  :11MM11M1MBMMR1@:              !        :1"
	@echo "                  UM11@8B11M@MMMMM@:             !        !1"
	@echo "                  1MMMMMR11M1MMMMMM1!           :!        !*"
	@echo "                 !1MMMMMMM1M1MMMMMMM1:          !!       ~1~"
	@echo "                 *11@@@1888M1MMMMMMMM1:         !!       !1"
	@echo "                  11MMMM@M1MRMMMMMMMM1W!        X~      :HT"
	@echo "                  *8MM@RRR1MMMMMMMMMMRRW        M     : ~1~"
	@echo "                  !1MMMMMM1MM8MMMMMMM8@1       .1eiou:  X1u"
	@echo "                  !!MMMM@R1MM1MMMMMMMMMMX   .uW11111111W111Wu um@@@@*Wu"
	@echo "                  *!MMMMB1*8MRMMMMMMMMMM1!:H118811111111111111@~~~~~~?*W."
	@echo "                   !11@^* ~1MMMMMMMMMMM111RM11BB1111111111111~~~~~~~~~~@W"
	@echo "                    ^(!    MMMMMMMMMMMM1RRM1RM1R11111111111@~~~~~~~~~~~!1"
	@echo "                     -!    !MMMMMMMMMM11MMM181BMR111111111*~~~~~~~~~~~~!1"
	@echo "                      *    !1MM@MMMMMM11@M1118111R8111111*~~~~~~~~~~~~!!1"
	@echo "                      !:   ~RMMMMMMMMMM1MMM11B88188R11111!~~~~~~~~~~~~~!1"
	@echo "                      (:    !MMM1MMMR1M18M11@^@1B1B1B111?~ ~~~~~~~~~~~~W!"
	@echo "                      !!     ?MMMMMMMR1118R1~  *@11111@^ ~ ~~~~~~~~~~~:1!"
	@echo "                      *W      MMMMMMMMR1811?     *@111~    ~::~~~~~~~~B*"
	@echo "                       1:     *MM1MMMMMM111~      XR1~       ~~~~~~~~!1!"
	@echo "                       ^W      !M18M88818MT       18!           ~~~~:1*"
	@echo "                        TX      ?M118M88R1~      XMM            ~~~~X1~"
	@echo "                        *1:     ~M1M@8MM1M      :11~            :~:!8T"
	@echo "                         *@      !18MR1M1~      11!              :!!1"
	@echo "                          !X      M1MMM1M      U8?             .!~~1~"
	@echo "                         .1BX     !1R18M!     !1?             :~ :WT"
	@echo "                  ........***!     RMMR1     :1?            :~   !1"
	@echo "             .ue1*@^^^*       :    ~@8M?     W?           :~    ~WT"
	@echo "         ue@*^^               ~:    ~*1!    !?          :~    ~~:1!"
	@echo "      .*^^*                     :     T     !~        :!        H*"
	@echo "    .~                          ~:    ~     ~!       !*        :1*"
	@echo "   !                             ~   ~~      !     :~         :1^"
	@echo "  (           ..:--~***~--:.     :   !      ::   .X..        x1^"
	@echo "  !                         *~--::X !     ~: !  !^   ~:   .uW1^"
	@echo "  !                                ~     -    ~!      *!W***^*"
	@echo " ~!                               ~ !  +.     !*        ^^^***^@W."
	@echo "  *X                             ! /*~ !~:   !~                ~*1:"
	@echo "   *\                            !~  ~  -.!!*                    *@e."
	@echo "     -eu.                       /     *-..!:                   -:.~1"
	@echo "      .^*11Woouu..............:~        X1*****@We=====mm*****Wu:!!1"


	@echo "\n"
	@echo "Compiling libft ..."
	@make -C libft/ all
	@echo "Compiling fractol ..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "Done !"

objs/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE_DIR) -o $@ -c $<

clean:
	@rm -rf objs
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "All clean !"

re: fclean all

norminette: 
	norminette $(SRC_DIR) ./libft ./incs

.PHONY: all clean fclean re norminette