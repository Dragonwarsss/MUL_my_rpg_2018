/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** display_pause.c
*/

#include "my.h"

void put_pause(game_t *game, sfRenderWindow *win)
{
    if (game->pause == 1)
        draw_scene(game->sc[sc_pause], win);
}