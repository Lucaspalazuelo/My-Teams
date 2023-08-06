##
## EPITECH PROJECT, 2023
## MyTeams - CLI
## File description:
## MAKEFILE file.
##

SRC = src/main.c \
	./src/parameters.c \
	./src/socket.c \
	./src/socket_loop.c \
	./src/close_socket.c \
	./src/connections_loop.c \
	./src/utils/error_handling.c \
	./src/utils/print_help.c \
	./src/utils/my_write.c \
	./src/utils/my_exit.c \
	./src/utils/my_free.c \
	./src/utils/str_to_args.c \
	./src/handle_command.c \
	./src/commands/login.c \
	./src/commands/logout.c \
	./src/utils/my_str_to_word_array.c \
	./src/commands/users.c \
	./src/commands/user.c \
	./src/commands/send.c \
	./src/utils/free_tab.c \
	./src/utils/tab_to_str.c \
	./src/commands/messages.c \
	./src/utils/str_to_time.c \
	./src/commands/use.c \
	./src/commands/create.c \
	./src/commands/list.c \
	./src/commands/info.c \
	./src/commands/subscribe.c \
	./src/commands/unsubscribe.c

OBJ = $(SRC:.c=.o)

PWD = $(shell pwd)

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -I ./inc/
LDFLAGS = -L ../libs/myteams/ -l myteams -l uuid

NAME = ../myteams_cli

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
