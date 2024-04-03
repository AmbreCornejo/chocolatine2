##
## EPITECH PROJECT, 2023
## makefile
## File description:
## mini_printf
##

NAME	=	libhashtable.a

SRCS	=	hash.c	\
		my_strlen.c		\
		hashtable.c	\
		hashtable_actions.c	\
		linked_lists.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_put_nbr.c

SRCS_TESTS	=	tests/tests.c	\
				hash.c	\
				my_strlen.c		\
				hashtable.c	\
				hashtable_actions.c	\
				linked_lists.c	\
				my_putchar.c	\
				my_putstr.c	\
				my_strcmp.c	\
				my_strcpy.c	\
				my_strdup.c	\
				my_put_nbr.c

OBJ	=	$(SRCS:.c=.o)

CFLAGS 	=	-Werror -Wall -Wextra

GTK_FLAGS = $(shell pkg-config --cflags --libs gtk+-3.0)

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) main.c -L. -lhashtable $(GTK_FLAGS) -o secured

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f *.gcda
	rm -f *.gcno

fclean: 	clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f secured

re:	fclean all

tests_run:
	rm -f *.gcda
	rm -f *.gcno
	gcc -o unit_tests $(SRCS_TESTS) --coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

debug:	all clean
	$(CC) main.c -L. -lhashtable $(GTK_FLAGS)
	./a.out
