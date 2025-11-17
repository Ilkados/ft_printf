CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = format_char.c format_int.c format_str.c format_ptr.c printf_entry.c

OFILES =	$(SRCS:.c=.o)

$(NAME): $(OFILES)

all: $(NAME)

%.o: %.c 
	$(CC) -c $(FLAGS) $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -rf  $(OFILES) 

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	clean
.SECONDARY: $(OFILES)