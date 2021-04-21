SRC = *.c

OBJ = ${SRC:.c=.o}

CC = gcc

FLGS = -Wall -Werror -Wextra

HEADER = libft.h

NAME = libft.a


.c.o :	$(HEADER)
	$(CC) $(FLGS) -c $(SRC) -I $(HEADER)

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME): all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean .c.o 