##
## EPITECH PROJECT, 2023
## B-CPE-110-MAR-1-1-settingup-selim.bouasker
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/game.c	\
		src/my_args.c	\
		src/return.c	\
		src/my_printf.c	\
		src/my_put_nbr.c	\
		src/my_put_nbr_recursive.c	\
		src/my_putchar.c	\
		src/int_to_str.c	\
		src/my_putstr.c	\
		src/cases.c	\

OBJ	=	$(SRC:.c=.o)

NAME	= my_hunter

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -I../includes $(CSFML) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
