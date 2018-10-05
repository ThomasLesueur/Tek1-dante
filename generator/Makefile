##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c						\
		src/init.c					\
		list/list.c					\
		src/maze_func.c					\
		src/check.c					\
		src/gen_perfect_maze.c				\
		src/gen_imperfect_maze.c			\
		src/next_cell.c					\
		src/manage_position.c				\
		src/free.c					\
		src/special_cases.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra

NAME	=	generator

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
