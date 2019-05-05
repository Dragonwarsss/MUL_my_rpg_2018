/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_key_invader
*/

#include "my.h"

static int delete_enn(ennemies_t *tmp, ennemies_t *prev,
ennemies_t *next, invader_t *invader)
{
    if (tmp->prev && tmp->next) {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }
    if (!prev && !next) {
        return (1);
    }
    if (!prev && next) {
        invader->ennemies = invader->ennemies->next;
        invader->ennemies->prev = NULL;
    }
    if (!next && prev)
        tmp = NULL;
    return (0);
}

void deal_damage_to_ennemy(ennemies_t *enn, sfRenderWindow *window,
invader_t *invader)
{
    ennemies_t *tmp = enn;
    sfVector2i pm = sfMouse_getPositionRenderWindow(window);

    for (; tmp; tmp = tmp->next) {
        tmp->pos = sfSprite_getPosition(tmp->sprite);
        if (pm.x >= tmp->pos.x && pm.x <= tmp->pos.x + tmp->rect.width &&
            pm.y >= tmp->pos.y && pm.y <= tmp->pos.y + tmp->rect.height)
            tmp->hp -= 3;
        if (tmp->hp <= 0)
            if (delete_enn(tmp, tmp->next, tmp->prev, invader)) {
                invader->ennemies = NULL;
                return;
            }
    }
}

void check_key_invader(sfEvent *event, game_t *game, sfRenderWindow *window)
{
    if (event->mouseButton.button == sfMouseLeft)
        deal_damage_to_ennemy(game->invader->ennemies, window, game->invader);
}
