/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** interact.c
*/

#include "my.h"

static int is_stairs(sfVector2f pos_p, map_t *map)
{
    int **map2 = map->map2;
    sfVector2i pos = (sfVector2i) {pos_p.x, pos_p.y};

    if (map2[pos.y][pos.x] == 1600 || map2[pos.y][pos.x] == 1601 ||
        map2[pos.y][pos.x] == 1700 || map2[pos.y][pos.x] == 1701)
        return (-1);
    if (map2[pos.y][pos.x] == 1800 || map2[pos.y][pos.x] == 1801 ||
        map2[pos.y][pos.x] == 1900 || map2[pos.y][pos.x] == 1901)
        return (1);
    return (0);
}

void interact(player_t *player, map_t *map, game_t *game)
{
    int next_map;

    if ((next_map = is_stairs(player->pos_map, map))) {
        game->map += next_map;
        if (next_map == -1) {
            player->pos_map = (sfVector2f) {26, 7};
            game->maps[game->map]->offset = (sfVector2f) {-11 * 16, 16};
        }
        if (next_map == 1) {
            player->pos_map = (sfVector2f) {29, 7};
            game->maps[game->map]->offset = (sfVector2f) {-14 * 16, 16};
        }
    }
}
