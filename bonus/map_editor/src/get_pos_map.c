/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** get_pos_map.c
*/

#include <SFML/Graphics.h>
#include "edit.h"

#ifndef TILE_SIZE
#define TILE_SIZE 70
#endif

sfVector2i get_pos_map(__attribute__((unused))edit_t *edit, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    int x = 0;
    int y = 0;
    int tile_size = edit->tile_size;

    for (; pos.x > (tile_size * edit->scale); pos.x -= (tile_size * edit->scale))
        x += 1;
    for (; pos.y > (tile_size * edit->scale); pos.y -= (tile_size * edit->scale))
        y += 1;
    pos.x = x;
    pos.y = y;
    return (pos);
}
