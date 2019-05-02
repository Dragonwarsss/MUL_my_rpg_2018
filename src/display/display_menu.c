/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_map
*/

#include "my.h"

static void check_button_menu(scene_t *sc, sfRenderWindow *window)
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

void display_menu(scene_t *sc, sfRenderWindow *window, sound_t *sound)
{
    check_button_menu(sc, window);
    draw_scene(sc, window);
}
