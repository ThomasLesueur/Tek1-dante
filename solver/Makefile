##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	main.c	\
		solver.c	\
		algo_path.c	\
		calc.c		\
		lists.c	\
		print_passed_path.c	\
		check.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra

NAME	=	solver

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
