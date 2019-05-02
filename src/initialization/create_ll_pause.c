/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_ll_pause.c
*/

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

sprite_t *create_ll_pause(void)
{
    sprite_t *tmp = NULL;

    tmp = push_ll(NULL, "asset/pause_res.png", (sfVector2f) {0, 0}, 1);
    if (!tmp)
        return (NULL);
    tmp->ptr = NULL;
    tmp = push_ll(tmp, "asset/pause_menu.png", (sfVector2f) {640, 0}, 0);
    if (!tmp)
        return (NULL);
    tmp->ptr = &change_scene_to_menu;
    tmp = push_ll(tmp, "asset/pause_quit.png", (sfVector2f) {1280, 0}, 0);
    if (!tmp)
        return (NULL);
    tmp->ptr = &quit_game;
    return (tmp);
}