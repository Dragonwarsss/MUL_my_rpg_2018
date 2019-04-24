/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** edit.c
*/

#include "edit.h"

int init(int ac, char **av, edit_t *edit)
{
    char *opt = "whslc";
    int stat = 0;

    set_struct(edit, av);
    stat = get_opt(ac, av, edit, opt);
    if (stat != 0)
        return (stat);
    if (edit->map_to_load != NULL)
        load_map(edit);
    return (0);
}
