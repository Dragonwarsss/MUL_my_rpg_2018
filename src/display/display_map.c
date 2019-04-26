/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** display_map.c
*/

#include <SFML/Graphics.h>
#include "my.h"

void display_map2(map_t *edit, sfRenderWindow *window)
{
    int height = edit->height;
    int width = edit->width;
    int tile_size = edit->tile_size;

    for (int i = 0; i != width; i += 1)
        for (int j = 0; j != height; j += 1) {
            edit->rect.left = edit->map2[i][j] / 100 * tile_size;
            edit->rect.top = edit->map2[i][j] % 100 * tile_size;
            edit->pos.x = (j * tile_size) * edit->scale + edit->offset.x;
            edit->pos.y = (i * tile_size) * edit->scale + edit->offset.y;
            sfSprite_setPosition(edit->sprite, edit->pos);
            sfSprite_setTextureRect(edit->sprite, edit->rect);
            sfRenderWindow_drawSprite(window, edit->sprite, NULL);
        }
}

void display_map(map_t *edit, sfRenderWindow *window)
{
    int height = edit->height;
    int width = edit->width;
    int tile_size = edit->tile_size;

    for (int i = 0; i != width; i += 1)
        for (int j = 0; j != height; j += 1) {
            edit->rect.left = edit->map[i][j] / 100 * tile_size;
            edit->rect.top = edit->map[i][j] % 100 * tile_size;
            edit->pos.x = (j * tile_size) * edit->scale + edit->offset.x;
            edit->pos.y = (i * tile_size) * edit->scale + edit->offset.y;
            sfSprite_setPosition(edit->sprite, edit->pos);
            sfSprite_setTextureRect(edit->sprite, edit->rect);
            sfRenderWindow_drawSprite(window, edit->sprite, NULL);
        }
    display_map2(edit, window);
}
