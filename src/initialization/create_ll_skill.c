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
    sfSprite_setScale(tmp->sprite, (sfVector2f) {3, 3});
    sfSprite_setPosition(tmp->sprite, pos);
    tmp->button = button;
    tmp->next = next;
    return (tmp);
}

sprite_t *create_ll_skill(void)
{
    sprite_t *tmp = NULL;

    tmp = push_ll(tmp, VALGRINDLV3, (sfVector2f) {1256, 0}, 1);
    tmp = push_ll(tmp, VALGRINDLV2, (sfVector2f) {936, 0}, 1);
    tmp = push_ll(tmp, VALGRINDLV1, (sfVector2f) {616, 0}, 1);
    tmp->rect.left = 48;
    sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    return (tmp);
}
