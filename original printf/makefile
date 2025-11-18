CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_print_str.c ft_print_address.c ft_print_nbr.c  ft_print_chr.c  ft_print_address put_hex_ul.c main.c

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