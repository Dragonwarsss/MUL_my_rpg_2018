/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** display_pause.c
*/

#include "my.h"

static void check_button_pause(scene_t *sc, sfRenderWindow *window)
{
    sfVector2i pm = sfMouse_getPositionRenderWindow(window);

    for (sprite_t *tmp = sc->ll_sprite; tmp; tmp = tmp->next) {
        tmp->rect.left = 0;
        if (pm.x >= tmp->pos.x && pm.x <= tmp->pos.x + tmp->rect.width &&
            pm.y >= tmp->pos.y && pm.y <= tmp->pos.y + tmp->rect.height &&
            tmp->button == 1)
            tmp->rect.left = sfSprite_getTextureRect(tmp->sprite).width;
        if (tmp->button)
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
}

void put_pause(game_t *game, sfRenderWindow *win)
{
    check_button_pause(game->sc[sc_pause], win);
    if (game->pause == 1)
        draw_scene(game->sc[sc_pause], win);
}