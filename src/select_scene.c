/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** select_scene
*/

#include "my.h"

void select_scene(game_t *g, sfRenderWindow *window)
{
    if (scene == 0)
        display_menu(g->sc[0], window);
    if (scene == 1)
        display_map(g, window);
}
