/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_key_press_scene.c
*/

#include <SFML/Graphics.h>
#include "my.h"

void change_skin(sfEvent *event, scene_t *sc)
{
    if (event->key.code == sfKeyLeft)
        if (sc->player->prev) {
            sc->player = sc->player->prev;
        }
    if (event->key.code == sfKeyRight)
        if (sc->player->next) {
            sc->player = sc->player->next;
        }
}

void check_key_press_scene(sfEvent *event, game_t *game)
{
    if (game->scene == sc_option)
        change_skin(event, game->sc[1]);
}
