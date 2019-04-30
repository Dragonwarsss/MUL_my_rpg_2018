/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_ll_options.c
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

sprite_t *create_ll_options(void)
{
    sprite_t *tmp = NULL;

    tmp = push_ll(NULL, "asset/opt_music_icon.png", (sfVector2f) {390, 580}, 1);
    if (!tmp)
        return (NULL);
    tmp->ptr = NULL;
    tmp = push_ll(tmp, "asset/opt_bg_template.png", (sfVector2f) {0, 0}, 0);
    if (!tmp)
        return (NULL);
    return (tmp);
}