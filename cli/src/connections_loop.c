/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** connections_loop.c file.
*/

#include "cli.h"

void connections_loop(parameters_t *p)
{
    char buffer[MAX_BODY_LENGTH] = { 0 };
    int nb = 0;

    nb = read(p->temporary_socket, buffer, MAX_BODY_LENGTH);
    if (nb == 0) {
        close_socket(p, true);
        exit(0);
    }
    if (p->command_processed == 1) {
        p->argv = realloc(p->argv, (p->count + 1) * sizeof(char *));
        p->argv[p->count] = malloc(sizeof(char) * MAX_BODY_LENGTH);
        p->argv[p->count] = strdup(buffer);
        p->count++;
    }
    if (nb > 0)
        connections_loop_read(buffer, p);
}

void connections_loop_read(char *buffer, parameters_t *p)
{
    printf("%s", buffer);
    handle_commands(p);
}

void input_loop(parameters_t *p)
{
    char buffer[MAX_BODY_LENGTH] = { 0 };

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        my_exit(84, "fgets failed\n", p);
    else
        input_loop_write(p, buffer);
}

void input_loop_write(parameters_t *p, char *buffer)
{
    char **args = my_str_to_word_array(buffer, " \r\t\n");

    for (int j = 0; j < MAX_BODY_LENGTH; j++) {
        if (buffer[j] == '\n') {
            buffer[j] = '\0';
        }
    }
    if (args[0] == NULL)
        return;
    if (p->command != NULL)
        free(p->command);
    p->command = strdup(args[0]);
    p->command_processed = 1;
    if (strcmp(p->command, "/use") == 0) {
        use(p, buffer);
        p->command_processed = 0;
    }
    my_write(p->temporary_socket, buffer);
}
