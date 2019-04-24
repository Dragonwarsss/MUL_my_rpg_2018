/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** select_map.c
*/

#include <SFML/Graphics.h>
#include "edit.h"

void select_map(edit_t *edit, sfRenderWindow *window, int max_x, int max_y)
{
    if (edit->ground == 0)
        put_block(edit, window, edit->map, max_x, max_y);
    else if (edit->ground == 1)
        put_block(edit, window, edit->map2, max_x, max_y);
}
