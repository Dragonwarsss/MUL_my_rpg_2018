/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_ll_invader
*/

#include <stdlib.h>
#include "my.h"

static sprite_t *push_ll_weapon(sprite_t *next, char *path, sfVector2f pos)
{
    sprite_t *tmp = malloc(sizeof(sprite_t));

    if (!tmp)
        return (NULL);
    tmp->next = next;
    tmp->sprite = sfSprite_create();
    tmp->texture = sfTexture_createFromFile(path, NULL);
    if (!tmp->sprite || !tmp->texture)
        return (NULL);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    tmp->rect = sfSprite_getTextureRect(tmp->sprite);
    tmp->rect.width /= 2;
    sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    sfSprite_setPosition(tmp->sprite, pos);
    sfSprite_scale(tmp->sprite, (sfVector2f) {3, 3});
    tmp->button = 0;
    tmp->pos = pos;
    return (tmp);
}

void init_weapon(invader_t *tmp)
{
    sfVector2f pos = (sfVector2f) {0, 0};

    tmp->weapons = malloc(sizeof(sprite_t));
    tmp->weapons = push_ll_weapon(NULL, VALGRINDLV1, pos);
    tmp->weapons->rect.left = 48;
    sfSprite_setTextureRect(tmp->weapons->sprite, tmp->weapons->rect);
    pos = (sfVector2f) {200, 0};
}

void init_ennemies(invader_t *tmp, int level)
{
    int enn = rand() % (int)(level * 3.25) + 2;

    tmp->ennemies = push_ll_enn(NULL, ENNEMIES, level);
    for (int i = 0; i != enn; i += 1)
        tmp->ennemies = push_ll_enn(tmp->ennemies, ENNEMIES, level);
}

invader_t *init_invader(UNUSED int level)
{
    invader_t *tmp = malloc(sizeof(invader_t));

    if (!tmp)
        return (NULL);
    tmp->level = 1;
    tmp->weapons = NULL;
    init_weapon(tmp);
    init_ennemies(tmp, level);
    my_puterr("weapon initialization done\n");
    return (tmp);
}
