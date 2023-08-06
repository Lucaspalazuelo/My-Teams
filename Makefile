##
## EPITECH PROJECT, 2023
## MyTeams
## File description:
## MAKEFILE file.
##

SERVER_PATH = ./server/
CLI_PATH = ./cli/

SERVER_BINARY = myteams_server
CLI_BINARY = myteams_cli

ADDITIONAL_FLAGS = -j 4

all:
	make -C $(SERVER_PATH) $(ADDITIONAL_FLAGS)
	make -C $(CLI_PATH) $(ADDITIONAL_FLAGS)

clean:
	make -C $(SERVER_PATH) clean
	make -C $(CLI_PATH) clean

fclean: clean
	make -C $(SERVER_PATH) fclean
	make -C $(CLI_PATH) fclean

re: fclean all
