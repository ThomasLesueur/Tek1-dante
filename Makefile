##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

all:
	make -C ./generator/
	make -C ./solver/

generator:
		make -C ./generator/

solver:
		make -C ./solver/

clean:
	rm -f generator/*.o
	rm -f generator/src/*.o
	rm -f generator/list/*.o
	rm -f solver/*.o

fclean: clean
	rm -f generator/generator
	rm -f solver/solver

re:	fclean all

.PHONY:	all clean fclean re
