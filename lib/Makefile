##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		=	libmy.a

EXTRA_FLAGS ?=

CPPFLAGS	+=	-I./include/ -W -Wall -Wextra -Werror $(EXTRA_FLAGS)

OBJ			=	$(SRCS:.c=.o)

SRCS		=	my_arraylen.c				\
				my_clean_str.c				\
				my_str_to_array.c			\
				my_free_array.c				\

all :	$(NAME)
$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re
