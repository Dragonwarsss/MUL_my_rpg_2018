/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_ll_ennemies.c
*/

#include <stdlib.h>
#include "my.h"

ennemies_t *push_ll_enn(ennemies_t *next, char *path, int level)
{
    ennemies_t *tmp = malloc(sizeof(ennemies_t));

    if (!tmp)
        return (NULL);
    tmp->next = next;
    tmp->prev = NULL;
    if (next)
        next->prev = tmp;
    tmp->sprite = sfSprite_create();
    tmp->texture = sfTexture_createFromFile(path, NULL);
    if (!tmp->sprite || !tmp->texture)
        return (NULL);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    tmp->rect = sfSprite_getTextureRect(tmp->sprite);
    tmp->hp = level * 1.5;
    tmp->pos = (sfVector2f) {rand() % 1920, rand() % 1080};
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    return (tmp);
}
