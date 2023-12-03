##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRV_DIR		=	./src/server/
CLI_DIR		=	./src/client/
TEST_DIR	=	./tests/
LIB_DIR		=	./lib/

all: server client
	@echo "Build myteams ok!"

server:
	@make -s -C $(SRV_DIR)

client:
	@make -s -C $(CLI_DIR)

debug:
	@make -s debug -C $(SRV_DIR)
	@make -s debug -C $(CLI_DIR)
	@echo "Build debug myteams ok!"

tests_run:
	@make -s -C $(TEST_DIR)
	@echo "Buld tests_run ok!"
	@gcovr --html --html-details -o $(TEST_DIR)cov.html
	@gcovr

clean:
	@make -s clean -C $(SRV_DIR)
	@make -s clean -C $(CLI_DIR)
	@make -s clean -C $(TEST_DIR)
	@echo "Clean myteams ok!"

fclean:
	@make -s fclean -C $(SRV_DIR)
	@make -s fclean -C $(CLI_DIR)
	@make -s fclean -C $(TEST_DIR)
	@echo "Fclean myteams ok!"

re: fclean all

.PHONY: all clean fclean re
