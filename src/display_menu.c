/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_map
*/

#include "my.h"

static void check_button_menu(scene_t *sc, sfRenderWindow *window)
{
    sprite_t *tmp = sc->ll_sprite;
    sfVector2i pm = sfMouse_getPositionRenderWindow(window);
    sfIntRect rect;

    while (tmp) {
        tmp->rect.left = 0;
        if (pm.x >= tmp->pos.x && pm.x <= tmp->pos.x + tmp->rect.width &&
            pm.y >= tmp->pos.y && pm.y <= tmp->pos.y + tmp->rect.height &&
            tmp->button == 1) {
            rect = sfSprite_getTextureRect(tmp->sprite);
            tmp->rect.left = rect.width;
        }
        if (tmp->button)
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
        tmp = tmp->next;
    }
}

void display_menu(scene_t *sc, sfRenderWindow *window)
{
    sprite_t *tmp = sc->ll_sprite;

    check_button_menu(sc, window);
    while (tmp) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
