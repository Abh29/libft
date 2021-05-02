SRC =	*.c

OBJ = ${SRC:.c=.o}

CC = gcc

FLGS = -Wall -Werror -Wextra

HEADER = libft.h

NAME = libft.a
NAMESO = libft.so


.c.o :	$(HEADER)
	$(CC) $(FLGS) -c ${SRC}

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME): all

bonus:	all

so:
	$(CC) -fPIC $(CFLAGS) -c $(SRC)
	gcc -shared -o $(NAMESO) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMESO)

re: fclean all

.PHONY: all clean fclean .c.o bonus

#&.c : &.o libft.a 