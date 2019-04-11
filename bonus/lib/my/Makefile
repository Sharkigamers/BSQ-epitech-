##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## task 01
##

SRC	=	my_strlen.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		the_putstr.c	\
		annex_putstr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
