##
## Makefile for Session 1 , Igraph
##
## Made by Penguin
## Lab'Anquise

NAME=		zdebug

SRC=		src/main.c \
		src/forest.c \
		src/burn.c \
		lib/print.c \
		lib/my_strdup.c \
		lib/cmalloc.c \

OBJ=		$(SRC:.c=.o)

CFLAGS +=	-W -Wall -Werror

CC=		gcc -g3 -Iinclude

RM=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lncurses

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
