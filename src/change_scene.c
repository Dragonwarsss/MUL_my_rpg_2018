/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** change_scene
*/

#include "my.h"

void change_scene_to_play(game_t *game, sprite_t *spr)
{
    (void) spr;

    game->scene = sc_map1;
}

void change_scene_to_settings(game_t *game, sprite_t *spr)
{
    (void) spr;

    game->scene = sc_option;
}

void quit_game(game_t *game, sprite_t *spr)
{
    (void) spr;

    game->quit = 1;
}

void change_scene_to_menu(game_t *game, sprite_t *spr)
{
    (void) spr;

    game->pause = 0;
    game->scene = sc_menu;
}