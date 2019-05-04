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

void move_map(sfEvent *event, game_t *game)
{
    if (event->key.code == sfKeyDown)
        check_key_down(game->maps[game->map],
        game->player, game->sounds, game->music);
    if (event->key.code == sfKeyUp)
        check_key_up(game->maps[game->map],
        game->player, game->sounds, game->music);
    if (event->key.code == sfKeyLeft)
        check_key_left(game->maps[game->map],
        game->player, game->sounds, game->music);
    if (event->key.code == sfKeyRight)
        check_key_right(game->maps[game->map],
        game->player, game->sounds, game->music);
}

void check_key_press_scene(sfEvent *event, game_t *game)
{
    if (game->scene == sc_option)
        change_skin(event, game->sc[1], game);
    if (game->scene == sc_option && event->key.code == sfKeyEscape) {
        game->scene = sc_menu;
        if (game->music)
            sfMusic_play(game->sounds[0]->music);
    } else if (event->key.code == sfKeyEscape && !game->pause)
        game->pause = 1;
    if (game->scene == sc_map1) {
        move_map(event, game);
        check_enter_key(event, game, game->player);
    }
}
