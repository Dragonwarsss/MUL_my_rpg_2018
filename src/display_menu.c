/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_map
*/

#include "my.h"

void display_menu(scene_t *sc, sfRenderWindow *window)
{
    sprite_t *tmp = sc->ll_sprite;

    while (tmp) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
