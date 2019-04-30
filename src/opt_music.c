/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** opt_music.c
*/

#include "my.h"

void put_music_or_not(game_t *game, sprite_t *spr)
{
    if (game->music) {
        spr->rect.left = spr->rect.width;
        sfSprite_setTextureRect(spr->sprite, spr->rect);
        game->music = 0;
    } else {
        spr->rect.left = 0;
        sfSprite_setTextureRect(spr->sprite, spr->rect);
        game->music = 1;
    }
}