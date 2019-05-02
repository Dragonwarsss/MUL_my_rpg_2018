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
    game->quit = 0;
    for (int i = 0; i != 3; i += 1)
        game->maps[i] = malloc(sizeof(map_t));
    game->maps[3] = NULL;
    load_map(game->maps[0], "maps/map1");
    load_map(game->maps[1], "maps/map2");
    set_map(game->maps[0]);
    set_map(game->maps[1]);
    return (0);
}

void init_scene(scene_t *sc, sprite_t *ll_sprite, player_t *player)
{
    sc->ll_sprite = ll_sprite;
    sc->player = player;
}

game_t *init_base(game_t *game)
{
    game->scene = 0;
    game->map = 1;
    game->music = 1;
    init_scene(game->sc[0], create_ll_menu(), NULL);
    init_scene(game->sc[1], create_ll_options(), create_ll_char());
    init_scene(game->sc[sc_pause], create_ll_pause(), NULL);
    game->player = init_player(game->sc[1]->player);
    game->sounds = init_music();
    if (!game->sounds)
        return (NULL);
    return (game);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->sc = malloc(sizeof(scene_t*) * 7);
    if (!game->sc)
        return (NULL);
    for (int i = 0; i != 7; i += 1) {
        game->sc[i] = malloc(sizeof(scene_t));
        if (!game->sc[i])
            return (NULL);
    }
    if (!init_base(game))
        return (NULL);
    if (!game->sc[0]->ll_sprite)
        return (NULL);
    if (init_maps(game) == 84)
        return (NULL);
    game->pause = 0;
    return (game);
}
