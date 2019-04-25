/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_ll_menu
*/

#include <stdlib.h>
#include "my.h"

static sprite_t *push_ll(sprite_t *next, char *path, sfVector2f pos, int button)
{
    sprite_t *tmp = malloc(sizeof(sprite_t));

    if (!tmp)
        return (NULL);
    tmp->sprite = sfSprite_create();
    tmp->texture = sfTexture_createFromFile(path, NULL);
    if (!tmp->sprite || !tmp->texture)
        return (NULL);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    tmp->pos = pos;
    if (button) {
        tmp->rect = sfSprite_getTextureRect(tmp->sprite);
        tmp->rect.width /= 2;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
    sfSprite_setPosition(tmp->sprite, pos);
    tmp->button = button;
    tmp->next = next;
    return (tmp);
}

sprite_t *create_ll_menu(void)
{
    sprite_t *tmp;

    tmp = push_ll(NULL, "asset/play.jpg", (sfVector2f) {0, 0}, 1);
    if (!tmp)
        return (NULL);
    tmp->ptr = &change_scene_to_play;
    tmp = push_ll(tmp, "asset/options.jpg", (sfVector2f) {1920 / 3, 0}, 1);
    if (!tmp)
        return (NULL);
    tmp->ptr = &change_scene_to_settings;
    tmp = push_ll(tmp, "asset/quit.jpg", (sfVector2f) {1920 / 3 * 2, 0}, 1);
    if (!tmp)
        return (NULL);
    tmp->ptr = &quit_game;
    return (tmp);
}
