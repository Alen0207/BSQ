##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=		$(addprefix src/,	\
			setting_up.c		\
			biggest_square.c	\
			generator.c			\
			main.c)				\

TEST	=	$(addprefix src/,	\
			biggest_square.c	\
			generator.c)		\

OBJ	=	$(SRC:.c=.o)

CC	?=	gcc

NAME	=	bsq

UNIT_TEST	=	unit_tests

CFLAGS	=	-Wall -Wextra

CPPFLAGS = -iquote ./include/ -iquote ./lib/

LDLIBS = -lmy

LDFLAGS = -L lib/

CRITERION 	=	--coverage -lcriterion

LIB	=	-L. -lmy

LIB_PATH	=	lib/my

all:	build_lib $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)  $(CFLAGS) $(LDFLAGS) $(LDLIBS)

build_lib:
	$(MAKE) -C lib/my

fclean_rules:
	rm -f

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJ)

fclean: fclean_rules clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)
	rm -f $(UNIT_TEST)

re:	 fclean all
