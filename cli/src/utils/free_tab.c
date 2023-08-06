/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** free_tab
*/

#include "cli.h"

void free_tab(parameters_t *p)
{
    if (p->argv == NULL)
        return;
    for (int i = 0; i < p->count; i++)
        free(p->argv[i]);
    free(p->argv);
    p->count = 0;
    p->argv = NULL;
}
