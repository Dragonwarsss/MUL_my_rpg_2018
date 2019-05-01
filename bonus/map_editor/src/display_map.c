/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** display_map.c
*/

#include <SFML/Graphics.h>
#include "edit.h"

#ifndef TILE_SIZE
#define TILE_SIZE 70
#endif

void display_map(edit_t *edit, sfRenderWindow *window, int **map)
{
    int height = edit->height;
    int width = edit->width;
    int tile_size = edit->tile_size;

    for (int i = 0; i != width; i += 1)
        for (int j = 0; j != height; j += 1) {
            edit->rect.left = map[i][j] / 100 * tile_size;
            edit->rect.top = map[i][j] % 100 * tile_size;
            edit->pos.x = (j * tile_size) * edit->scale +
            (edit->offset.x * edit->scale);
            edit->pos.y = (i * tile_size) * edit->scale +
            (edit->offset.y * edit->scale);
            sfSprite_setPosition(edit->sprite, edit->pos);
            sfSprite_setTextureRect(edit->sprite, edit->rect);
            sfRenderWindow_drawSprite(window, edit->sprite, NULL);
        }
}
