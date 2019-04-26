/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** select_scene
*/

#include "my.h"

void select_scene(game_t *game, sfRenderWindow *window)
{
    if (game->scene == sc_menu)
        display_menu(game->sc[0], window);
    if (game->scene == sc_map1)
        display_map(game->maps[0], window);
    if (game->scene == sc_option)
        display_option(game->sc[1], window);
    if (game->scene == sc_skill_tree)
        display_skill_tree(game, window);
}
