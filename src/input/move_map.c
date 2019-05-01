/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** move_map
*/

#include <SFML/Graphics.h>
#include "my.h"

void move_map_down(sfVector2f *pos, int tile_size, player_t *player)
{
    (*pos).y -= tile_size;
    player->rect.top = 0;
}

void move_map_up(sfVector2f *pos, int tile_size, player_t *player)
{
    (*pos).y += tile_size;
    player->rect.top = 196;
}

void move_map_left(sfVector2f *pos, int tile_size, player_t *player)
{
    (*pos).x += tile_size;
    player->rect.top = 64;
}

void move_map_right(sfVector2f *pos, int tile_size, player_t *player)
{
    (*pos).x -= tile_size;
    player->rect.top = 128;
}
