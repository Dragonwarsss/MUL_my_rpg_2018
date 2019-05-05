/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_enter_key
*/

#include <stdio.h>
#include "my.h"

static void check_skill(sfEvent *event, game_t *game)
{
    if (event->key.code == sfKeyI)
        game->scene = sc_skill_tree;
}

void check_enter_key(sfEvent *event, game_t *game, player_t *player)
{
    sfVector2i pos = (sfVector2i) {player->pos_map.x, player->pos_map.y};

    if (game->text && event->key.code == sfKeyReturn) {
        if (game->text->len != my_strlen(game->text->msg)) {
            game->text->len = my_strlen(game->text->msg);
            return;
        }
        game->text = game->text->next;
        if (!game->text)
            start_clock(game->timer);
        return;
    }
    if (event->key.code == sfKeyReturn && player->rect.top == 196 &&
        game->maps[game->map]->map2[pos.y - 1][pos.x] == 1406)
        game->scene = sc_invader;
    if (event->key.code == sfKeyReturn && player->rect.top == 196 &&
    game->maps[game->map]->map2[pos.y - 1][pos.x] == 617) {
        sfClock_restart(game->timer->clock);
        game->text = create_ll_text_restart();
    }
    check_skill(event, game);
}
