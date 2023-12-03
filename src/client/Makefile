##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	myteams_cli

CPPFLAGS	=	-W -Wall -Wextra -Werror

CFLAGS		= 	-I../../include/client/ \
				-I$(LIB)include/ 		\
				-I../../libs/myteams/	\

LFLAGS 		= 	-L $(LIB) -lmy -L ../../libs/myteams/ -lmyteams -luuid

LIB			=	../../lib/
RFC_R		=	rfc_responses/

SRCS		=	main.c									\
				check_errors.c							\
				client.c								\
				init_client.c							\
				handle_events.c							\
				utils_client.c							\
				$(RFC_R)rfc_help.c						\
				$(RFC_R)rfc_usage.c						\
				$(RFC_R)rfc_connection.c				\
				$(RFC_R)rfc_subscription.c				\
				$(RFC_R)rfc_creation.c					\
				$(RFC_R)rfc_event.c						\
				$(RFC_R)rfc_individual_info.c			\
				$(RFC_R)rfc_global_info.c				\
				$(RFC_R)rfc_unknow_info.c				\
				$(RFC_R)rfc_no_data.c					\
				$(RFC_R)rfc_command_error.c				\
				$(RFC_R)rfc_authorization_error.c		\
				$(RFC_R)rfc_existing_request_error.c	\
				$(RFC_R)rfc_utils.c						\

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)
	@echo "Build client ok!"

build_lib :
	make -C $(LIB) EXTRA_FLAGS="$(EXTRA_FLAGS)"

$(NAME): build_lib $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LFLAGS)
	mv $(NAME) ../../

debug: CPPFLAGS += -g3
debug: EXTRA_FLAGS=-g3
debug: all
	@echo "Build client debug ok!"

clean:
	$(RM) $(OBJS)
	@echo "Clean client ok!"

fclean: clean
	$(RM)  ../../$(NAME)
	@echo "Fclean client ok!"

re: fclean all

.PHONY: all build_lib debug tests_run clean fclean re
