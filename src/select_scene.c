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
    if (game->scene == sc_skill_tree)
        display_skill_tree(game, window);
>>>>>>> f391f422ed33d637e93931dfc511e0fab417d66c
}
