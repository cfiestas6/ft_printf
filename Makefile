NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MY_SOURCES = ft_printf.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@cd libft ; make
	@cp ${LIBFT} ${NAME}
	@ar rsc  $(NAME) $(MY OBJECTS) ${LIBFT}

clean:
	@cd libft ; make clean
	@rm -f $(MY_OBJECTS)
fclean:
	@cd libft ; make fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

