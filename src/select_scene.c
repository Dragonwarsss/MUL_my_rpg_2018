/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** select_scene
*/

#include "my.h"

void select_scene(game_t *game, sfRenderWindow *window)
{
    if (game->scene == sc_menu) {
        game->pause = 0;
        display_menu(game->sc[0], window, game->sounds[0]);
    }
    if (game->scene == sc_map1)
        display_game(game, window);
    if (game->scene == sc_option) {
        game->pause = 0;
        display_option(game->sc[1], window);
    }
    if (game->scene == sc_skill_tree)
        display_skill_tree(game, window);
    if (game->scene == sc_invader)
        display_invader(game->invader, window);
    project_end(game, game->invader);
}
