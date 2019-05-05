/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** project_end.c
*/

#include "my.h"

void project_end(game_t *game, invader_t *invader)
{
    static int i = 0;

    if (invader->ennemies == NULL) {
        invader->level += 1;
        init_ennemies(invader, invader->level);
        if (!i) {
            game->text = create_ll_text_end();
            i += 1;
        }
        game->scene = sc_map1;
        sfClock_restart(game->timer->clock);
        game->timer->on = 0;
    }
}
