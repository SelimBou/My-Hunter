##
## EPITECH PROJECT, 2023
## B-CPE-110-MAR-1-1-settingup-selim.bouasker
## File description:
## Makefile
##

SRC	=	main.c	\
		game.c	\
		my_args.c	\
		return.c	\
		my_printf.c	\
		my_put_nbr.c	\
		my_put_nbr_recursive.c	\
		my_putchar.c	\
		int_to_str.c	\
		my_putstr.c	\
		cases.c	\

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
