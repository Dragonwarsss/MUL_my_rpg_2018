/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_option
*/

#include <SFML/Graphics.h>
#include "my.h"

void display_option(scene_t *sc, sfRenderWindow *window)
{
    sfSprite_setPosition(sc->player->sprite, sc->player->pos);
    draw_scene(sc, window);
}
