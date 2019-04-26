/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_ll_char
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"

static void *push_ll(player_t *next, char *path, int id)
{
    player_t *tmp = malloc(sizeof(player_t));

    if (!tmp)
        return (NULL);
    tmp->id = id;
    tmp->sprite = sfSprite_create();
    tmp->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    tmp->rect = sfSprite_getTextureRect(tmp->sprite);
    tmp->rect.width /= 3;
    tmp->rect.height /= 4;
    tmp->pos = (sfVector2f) {0, 0};
    tmp->next = next;
    tmp->prev = NULL;
    if (next)
        next->prev = tmp;
    return (tmp);
}

void *create_ll_char(void)
{
    player_t *tmp = push_ll(NULL, "asset/characters/char1.png", 1);

    tmp = push_ll(tmp, "asset/characters/char2.png", 2);
    tmp = push_ll(tmp, "asset/characters/char3.png", 3);
    tmp = push_ll(tmp, "asset/characters/char4.png", 4);
    return (tmp);
}
