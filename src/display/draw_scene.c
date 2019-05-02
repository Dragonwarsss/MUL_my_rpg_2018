/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** draw_scene
*/

#include <SFML/Graphics.h>
#include "my.h"

void show_ll_sprite(sprite_t *ll_sprite, sfRenderWindow *window)
{
    for (sprite_t *tmp = ll_sprite; tmp; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}

void show_player(player_t *player, sfRenderWindow *window)
{
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}

void draw_scene(scene_t *sc, sfRenderWindow *window)
{
    if (sc->ll_sprite)
        show_ll_sprite(sc->ll_sprite, window);
    if (sc->player)
        show_player(sc->player, window);
}