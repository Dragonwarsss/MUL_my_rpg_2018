/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** exec_mouse_button_scene
*/

#include "my.h"

void exec_mouse_button_scene(game_t *game, sfRenderWindow *window)
{
    if (game->scene == sc_menu)
        manage_menu_input(game, window);
}
