##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	myteams_server

CPPFLAGS	=	-W -Wall -Wextra -Werror

CFLAGS		= 	-I ../../include/server/	\
				-I ../../include/ 			\
				-I$(LIB)include/ 			\
				-I../../libs/myteams/		\
				-I$(DESTROY)				\
				-I$(CMD)					\
				-I$(DATA)					\
				-I$(GETTER)					\
				-I$(TOOLS)					\
				-I$(SAVE)					\

LFLAGS 		= 	-L $(LIB) -lmy -L ../../libs/myteams/ -lmyteams -luuid

LIB			=	../../lib/

CMD			=	./command/
DATA		=	./data/
DESTROY		=	./destroy/
SAVE		=	./save/
LOAD		=	./load/
TOOLS		=	./tools/
GETTER		=	$(DATA)getter/

SRCS		=	main.c								\
				check_errors.c						\
				server.c							\
				init_server.c						\
				handle_events.c						\
				$(DATA)handle_clients.c				\
				$(DATA)handle_replies.c				\
				$(DATA)handle_discussions.c			\
				$(DATA)handle_teams.c				\
				$(DATA)handle_channels.c			\
				$(DATA)handle_threads.c				\
				$(DATA)handle_subscriptions.c		\
				$(DATA)utils_data.c					\
				$(GETTER)getter_clients.c			\
				$(GETTER)getter_replies.c			\
				$(GETTER)getter_discussions.c		\
				$(GETTER)getter_teams.c				\
				$(GETTER)getter_channels.c			\
				$(GETTER)getter_threads.c			\
				$(GETTER)getter_subscriptions.c		\
				$(CMD)handle_cmd.c					\
				$(CMD)utils_cmd.c					\
				$(CMD)help.c						\
				$(CMD)login.c						\
				$(CMD)logout.c						\
				$(CMD)users.c						\
				$(CMD)user.c						\
				$(CMD)send.c						\
				$(CMD)messages.c					\
				$(CMD)subscribe.c					\
				$(CMD)subscribed.c					\
				$(CMD)unsubscribe.c					\
				$(CMD)use.c							\
				$(CMD)create.c						\
				$(CMD)list.c						\
				$(CMD)info.c						\
				$(SAVE)save.c						\
				$(SAVE)save_clients.c				\
				$(SAVE)save_channels.c				\
				$(SAVE)save_discussions.c			\
				$(SAVE)save_replies.c				\
				$(SAVE)save_subscriptions.c			\
				$(SAVE)save_teams.c					\
				$(SAVE)save_threads.c				\
				$(LOAD)load.c						\
				$(LOAD)load_teams.c					\
				$(LOAD)load_clients.c				\
				$(LOAD)load_channels.c				\
				$(LOAD)load_discussions.c			\
				$(LOAD)load_threads.c				\
				$(LOAD)load_replies.c				\
				$(LOAD)load_subscriptions.c			\
				$(LOAD)utils_load.c					\
				$(DESTROY)destroy.c					\
				$(DESTROY)destroy_clients.c			\
				$(DESTROY)destroy_teams.c			\
				$(DESTROY)destroy_channels.c		\
				$(DESTROY)destroy_threads.c			\
				$(DESTROY)destroy_replies.c			\
				$(DESTROY)destroy_discussions.c		\
				$(DESTROY)destroy_subscriptions.c	\
				$(TOOLS)utils_server.c				\
				$(TOOLS)utils_finder_uuid.c			\
				$(TOOLS)utils_finder_name.c			\

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)
	@echo "Build server ok!"

$(NAME): build_lib $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LFLAGS)
	mv $(NAME) ../../

build_lib :
	make -C $(LIB) EXTRA_FLAGS="$(EXTRA_FLAGS)"

debug: CPPFLAGS += -g3
debug: EXTRA_FLAGS=-g3
debug: all
	@echo "Build server debug ok!"

clean:
	$(RM) $(OBJS)
	@echo "Clean server ok!"

fclean: clean
	$(RM)  ../../$(NAME)
	@echo "Fclean server ok!"

re: fclean all

.PHONY: all build_lib debug tests_run clean fclean re
