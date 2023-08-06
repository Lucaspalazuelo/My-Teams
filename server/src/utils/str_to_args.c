/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** str_to_args.c file.
*/

#include "core.h"

str_to_args_t *str_to_args(const char *str)
{
    str_to_args_t *s = NULL;

    if (strlen(str + 1) > BUFFER_SIZE) {
        return (NULL);
    }
    s = str_to_args_malloc();
    if (s == NULL) {
        return (NULL);
    }
    return (str_to_args_loop(s, str));
}

str_to_args_t *str_to_args_loop(str_to_args_t *s, const char *str)
{
    unsigned int in_double_quotes = 0;

    for (unsigned int i = 0, j = 0; str[i] != '\0'; i++) {
        if (str_to_args_compute_logic(s, str[i],
            &in_double_quotes, &j) == false) {
            str_to_args_destroy(s);
            return (NULL);
        }
    }
    if (in_double_quotes == 1) {
        str_to_args_destroy(s);
        return (NULL);
    }
    return (s);
}

bool str_to_args_compute_logic(str_to_args_t *s, char current_char,
    unsigned int *in_double_quotes, unsigned int *j)
{
    if (current_char == '"') {
        *in_double_quotes = !(*in_double_quotes);
        if (*in_double_quotes == 1) {
            s->nb_args++;
            *j = 0;
        }
        return (true);
    }
    if (s->nb_args > STR_TO_ARGS_MAX_ARGS) {
        return (false);
    }
    if (*in_double_quotes == 1) {
        s->args[s->nb_args - 1][*j] = current_char;
        (*j)++;
    }
    return (true);
}

str_to_args_t *str_to_args_malloc(void)
{
    str_to_args_t *s = malloc(sizeof(str_to_args_t));

    if (s == NULL) {
        return (NULL);
    }
    s->nb_args = 0;
    s->args = malloc(sizeof(char *) * STR_TO_ARGS_MAX_ARGS);
    if (s->args == NULL) {
        str_to_args_destroy(s);
        return (NULL);
    }
    for (int i = 0; i < STR_TO_ARGS_MAX_ARGS; i++) {
        s->args[i] = malloc(sizeof(char) * BUFFER_SIZE);
        if (s->args[i] == NULL) {
            str_to_args_destroy(s);
            return (NULL);
        }
        memset(s->args[i], '\0', BUFFER_SIZE);
    }
    return (s);
}

void str_to_args_destroy(str_to_args_t *s)
{
    if (s != NULL && s->args != NULL) {
        for (int i = 0; i < STR_TO_ARGS_MAX_ARGS; i++) {
            my_free(s->args[i]);
        }
    }
    if (s != NULL) {
        my_free(s->args);
    }
    my_free(s);
}
