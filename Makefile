NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MY_SOURCES = ft_printf.c\
	     ft_putchar.c\
	     ft_putnbr.c\
	     ft_putstr.c\
	     ft_strlen.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)


$(NAME): $(MY_OBJECTS) ft_printf.h
	ar -rsc  $(NAME) $(MY OBJECTS)

all: $(NAME)

clean:
	@rm -f $(MY_OBJECTS)
fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
