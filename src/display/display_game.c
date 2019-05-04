/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_game
*/

#include "map.h"
#include "my.h"

void player_event(UNUSED game_t *game, UNUSED sfRenderWindow *window)
{
    interact(game->player, game->maps[game->map], game);
}

void display_game(game_t *game, sfRenderWindow *window)
{
    display_map(game->maps[game->map], window);
    display_player(game->player, window);
    player_event(game, window);
    if (game->text) {
        sfRenderWindow_drawSprite(window, game->utils[0]->sprite, NULL);
        display_text(game->text, window);
    }
}
