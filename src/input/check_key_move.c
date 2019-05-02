/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_key_move
*/

#include <stdio.h>
#include "my.h"

void check_key_up(map_t *map, player_t *player)
{
    int **map1 = map->map;
    int **map2 = map->map2;
    int x = player->pos_map.x;
    int y = player->pos_map.y - 1;

    if (y < 0)
        return;
    player->rect.top = 196;
    if (!collide(map1[y][x]) && !collide(map2[y][x])) {
        move_map_up(&map->offset, 16, player);
        player->pos_map.y -= 1;
        return;
    }
}

void check_key_down(map_t *map, player_t *player)
{
    int **map1 = map->map;
    int **map2 = map->map2;
    int x = player->pos_map.x;
    int y = player->pos_map.y + 1;

    if (y + 1 > map->height)
        return;
    player->rect.top = 0;
    if (!collide(map1[y][x]) && !collide(map2[y][x])) {
        move_map_down(&map->offset, 16, player);
        player->pos_map.y += 1;
        return;
    }
}

void check_key_left(map_t *map, player_t *player)
{
    int **map1 = map->map;
    int **map2 = map->map2;
    int x = player->pos_map.x - 1;
    int y = player->pos_map.y;

    if (x < 0)
        return;
    player->rect.top = 64;
    if (!collide(map1[y][x]) && !collide(map2[y][x])) {
        move_map_left(&map->offset, 16, player);
        player->pos_map.x -= 1;
        return;
    }
}

void check_key_right(map_t *map, player_t *player)
{
    int **map1 = map->map;
    int **map2 = map->map2;
    int x = player->pos_map.x + 1;
    int y = player->pos_map.y;

    if (x > map->width)
        return;
    player->rect.top = 128;
    if (!collide(map1[y][x]) && !collide(map2[y][x])) {
        move_map_right(&map->offset, 16, player);
        player->pos_map.x += 1;
        return;
    }
}
