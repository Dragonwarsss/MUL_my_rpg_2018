/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_player
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

player_t *init_player(player_t *ptr)
{
    player_t *tmp = malloc(sizeof(player_t));

    if (!tmp)
        return (NULL);
    tmp->id = 0;
    tmp->scale = 1;
    tmp->sprite = sfSprite_create();
    tmp->texture = ptr->texture;
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    tmp->rect = sfSprite_getTextureRect(tmp->sprite);
    tmp->rect.width /= 3;
    tmp->rect.height /= 4;
    tmp->pos = (sfVector2f) {960, 512};
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    tmp->next = NULL;
    tmp->prev = NULL;
    return (tmp);
}
