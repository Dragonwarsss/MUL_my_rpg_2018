/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** get_opt.c
*/

#include "edit.h"
#include "my.h"

static int manage_opt(edit_t *edit, char opt, char *elem)
{
    int stat = 0;

    switch (opt) {
    case 'l':
        edit->map_to_load = elem;
        edit->map_to_save = elem;
        break;
    case 'h':
        edit->tile_size = my_atoi(elem);
        break;
    case 'w':
        edit->tile_size = my_atoi(elem);
        break;
    case 's':
        edit->map_to_save = elem;
        break;
    case 'c':
        stat = load_conf(elem, edit);
        break;
    }
    return (stat);
}

static int is_opt(char c, char *opt)
{
    int i = 0;

    for (; i != my_strlen(opt); i += 1)
        if (c == opt[i])
            return (1);
    return (0);
}

int get_opt(int ac, char **av, edit_t *edit, char *opt)
{
    int i = 0;
    int stat = 0;

    for (; i != ac; i += 1)
        if (av[i][0] == '-' && is_opt(av[i][1], opt))
            stat = manage_opt(edit, av[i][1], av[i + 1]);
    return (stat);
}
