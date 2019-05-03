/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_enter_key
*/

#include <stdio.h>
#include "my.h"

void check_enter_key(sfEvent *event, game_t *game, player_t *player)
{
    sfVector2i pos = (sfVector2i) {player->pos_map.x, player->pos_map.y};

    if (event->key.code == sfKeyReturn && player->rect.top == 196 &&
        game->maps[game->map]->map2[pos.y - 1][pos.x] == 1406)
        printf("key pressed and computer in front of player\n");
    if (event->key.code == sfKeyReturn && player->rect.top == 196 &&
        game->maps[game->map]->map2[pos.y - 1][pos.x] == 617)
        printf("key pressed and distributor in front of player\n");
}
