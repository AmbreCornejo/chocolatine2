##
## EPITECH PROJECT, 2023
## makefile
## File description:
## navy
##

NAME	=	my_navy

SRCS	=	main.c	\
			my_strcmp.c	\
			display.c	\
			my_put_nbr.c	\
			my_putchar.c	\
			load.c	\
			my_strlen.c	\
			parsing.c	\
			connect.c	\
			my_getnbr.c	\
			error.c	\
			attack.c	\
			players_handle.c	\
			singleton.c	\
			win.c

SRCS_TESTS	=	my_getnbr.c	\
				my_put_nbr.c	\
				my_strcmp.c	\
				my_strlen.c	\
				my_putchar.c	\
				display.c	\
				error.c	\
				parsing.c	\
				load.c	\
				singleton.c	\
				win.c

OBJ	=	$(SRCS:.c=.o)

CFLAGS 	=	-Werror -Wall -Wextra

LDFLAGS	=	--coverage -lcriterion

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gc*

fclean: 	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

tests_run:
	rm -f *.gcda
	rm -f *.gcno
	gcc -o unit_tests $(SRCS_TESTS) tests/tests.c --coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
