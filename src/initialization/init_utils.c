/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_utils.c
*/

#include <stdlib.h>
#include "my.h"

static sprite_t *init_sprite(char *asset, int button)
{
    sprite_t *tmp = malloc(sizeof(sprite_t));

    if (!tmp)
        return (NULL);
    tmp->sprite = sfSprite_create();
    tmp->texture = sfTexture_createFromFile(asset, NULL);
    if (!tmp->sprite || !tmp->texture)
        return (NULL);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    tmp->next = NULL;
    sfSprite_setPosition(tmp->sprite, (sfVector2f) {615, 935});
    if (button) {
        tmp->rect = sfSprite_getTextureRect(tmp->sprite);
        tmp->rect.width /= 2;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
    return (tmp);
}

sprite_t **init_utils(void)
{
    sprite_t **tmp = malloc(sizeof(sprite_t*) * 3);

    if (!tmp)
        return (NULL);
    tmp[2] = NULL;
    tmp[0] = init_sprite("ressources/asset/text_box.png", 0);
    return (tmp);
}
