/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manage menu input
*/

#include "my.h"

void manage_menu_input(game_t *game, sfRenderWindow *window)
{
    sprite_t *tmp = game->sc[game->scene]->ll_sprite;
    sfVector2i pm = sfMouse_getPositionRenderWindow(window);

    while (tmp) {
        if (pm.x >= tmp->pos.x && pm.x <= tmp->pos.x + tmp->rect.width &&
        pm.y >= tmp->pos.y && pm.y <= tmp->pos.y + tmp->rect.height &&
        tmp->button) {
            tmp->ptr(game, tmp);
            sfMusic_stop(game->sounds[0]->music);
            break;
        }
        tmp = tmp->next;
    }
}

void manage_pause_input(game_t *game, sfRenderWindow *window)
{
    sprite_t *tmp = game->sc[sc_pause]->ll_sprite;
    sfVector2i pm = sfMouse_getPositionRenderWindow(window);

    while (tmp) {
        if (pm.x >= tmp->pos.x && pm.x <= tmp->pos.x + tmp->rect.width &&
        pm.y >= tmp->pos.y && pm.y <= tmp->pos.y + tmp->rect.height &&
        tmp->button) {
            tmp->ptr(game, tmp);
            break;
        }
        tmp = tmp->next;
    }
}