##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compilation
##

SRC	=	src/my_bsq.c	\
		src/stock_map_bsq.c	\
		src/annex_bsq.c	\
		src/gest_error.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include/

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	cd ../..
	gcc -o $(NAME) $(SRC) $(LIB) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	cd lib/my && make clean
	cd ../../
	cd src/ && rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && make fclean

re:	fclean all

.PHONY: all clean fclean uclean re
