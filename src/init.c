/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"

static void set_map(map_t *map)
{
    map->tile_size = 16;
    map->scale = 4;
    map->offset = (sfVector2f) {0, 0};
    map->rect = (sfIntRect) {0, 0, map->tile_size, map->tile_size};
    map->pos = (sfVector2f) {0, 0};
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile("asset/interior_tileset.png", NULL);
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setScale(map->sprite, (sfVector2f) {map->scale, map->scale});
}

int init_maps(game_t *game)
{
    game->maps = malloc(sizeof(map_t*) * 4);

    if (!game->maps)
        return (84);
    for (int i = 0; i != 3; i += 1)
        game->maps[i] = malloc(sizeof(map_t));
    game->maps[3] = NULL;
    load_map(game->maps[0], "maps/map1");
    set_map(game->maps[0]);
    return (0);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->scene = 0;
    game->sc = malloc(sizeof(scene_t*) * 5);
    if (!game->sc)
        return (NULL);
    for (int i = 0; i != 4; i += 1) {
        game->sc[i] = malloc(sizeof(scene_t));
        if (!game->sc[i])
            return (NULL);
    }
    game->sc[0]->ll_sprite = create_ll_menu();
    if (!game->sc[0]->ll_sprite)
        return (NULL);
    if (init_maps(game) == 84)
        return (NULL);
    return (game);
}
