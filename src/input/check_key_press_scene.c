/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_key_press_scene.c
*/

#include <SFML/Graphics.h>
#include "my.h"

void change_skin(sfEvent *event, scene_t *sc, game_t *game)
{
    if (event->key.code == sfKeyLeft)
        if (sc->player->prev) {
            sc->player = sc->player->prev;
            game->player->texture = sc->player->texture;
            sfSprite_setTexture(game->player->sprite,
            game->player->texture, sfFalse);
        }
    if (event->key.code == sfKeyRight)
        if (sc->player->next) {
            sc->player = sc->player->next;
            game->player->texture = sc->player->texture;
            sfSprite_setTexture(game->player->sprite,
            game->player->texture, sfFalse);
        }
}

void check_key_press_scene(sfEvent *event, game_t *game)
{
    if (game->scene == sc_option)
        change_skin(event, game->sc[1], game);
    if (event->key.code == sfKeyEscape)
        game->scene = sc_menu;
}
