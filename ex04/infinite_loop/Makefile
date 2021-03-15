##
## EPITECH PROJECT, 2021
## Workshop_Signals
## File description:
## Makefile
##

SRC		=	infinite_loop.c

OBJ		=	$(SRC:.c=.o)

NAME	=	infinite_loop

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re