/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** change_scene
*/

#include "my.h"

void change_scene_to_play(game_t *game)
{
    game->scene = 1;
}

void change_scene_to_settings(game_t *game)
{
    game->scene = 2;
}

void quit_game(game_t *game)
{
    game->quit = 1;
}
