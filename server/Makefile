##
## EPITECH PROJECT, 2023
## MyTeams - Server
## File description:
## MAKEFILE file.
##

SRC = ./src/main.c \
	./src/parameters.c \
	./src/load_users.c \
	./src/buffer.c \
	./src/commands/handle_help.c \
	./src/commands/handle_logout.c \
	./src/commands/use/channel_context.c \
	./src/commands/use/handle_use.c \
	./src/commands/use/no_context.c \
	./src/commands/use/team_context.c \
	./src/commands/use/thread_context.c \
	./src/commands/info/handle_info.c \
	./src/commands/info/channel_context.c \
	./src/commands/info/thread_context.c \
    ./src/commands/info/no_context.c \
    ./src/commands/info/team_context.c \
	./src/commands/create/handle_create.c \
    ./src/commands/create/no_context.c \
    ./src/commands/create/channel_context.c \
    ./src/commands/create/thread_context.c \
    ./src/commands/create/team_context.c \
    ./src/commands/list/handle_list.c \
    ./src/commands/list/no_context.c \
    ./src/commands/list/channel_context.c \
    ./src/commands/list/thread_context.c \
    ./src/commands/list/team_context.c \
	./src/commands/print_messages/handle_print_messages.c \
	./src/commands/print_messages/loop.c \
	./src/commands/print_users/handle_print_users.c \
	./src/commands/print_users/loop.c \
	./src/commands/print_user/handle_print_user.c \
	./src/commands/print_user/success.c \
	./src/commands/send/handle_send.c \
	./src/commands/send/success.c \
	./src/commands/send/add.c \
	./src/commands/subscribe/handle_subscribe.c \
	./src/commands/subscribe/success.c \
	./src/commands/authentification/handle_login.c \
	./src/commands/authentification/success.c \
	./src/commands/authentification/dispatcher.c \
	./src/commands/authentification/login.c \
	./src/commands/authentification/register.c \
	./src/sockets/init.c \
	./src/sockets/create.c \
	./src/sockets/close.c \
	./src/sockets/loop.c \
	./src/utils/sockets/valid_response.c \
	./src/utils/sockets/invalid_thread.c \
	./src/utils/sockets/invalid_subscription.c \
	./src/utils/sockets/invalid_user.c \
	./src/utils/sockets/already_subscribed.c \
	./src/utils/sockets/invalid_team.c \
	./src/utils/sockets/invalid_channel.c \
	./src/utils/files/add_line.c \
	./src/utils/files/search_line.c \
	./src/utils/error_handling.c \
	./src/utils/is_user_connected.c \
	./src/utils/is_team_validated.c \
	./src/utils/is_thread_validated.c \
	./src/utils/is_channel_validated.c \
	./src/utils/is_subscription_validated.c \
	./src/utils/is_user_validated.c \
	./src/utils/generate_uuid.c \
	./src/utils/print_help.c \
	./src/utils/send_global_event.c \
	./src/utils/send_event.c \
	./src/utils/my_write.c \
	./src/utils/my_exit.c \
	./src/utils/destroy_general_handle.c \
	./src/utils/get_timestamp.c \
	./src/utils/str_to_args.c \
	./src/utils/my_free.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./inc/
LDFLAGS = -L ../libs/myteams/ -l myteams -l uuid

NAME = ../myteams_server

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
