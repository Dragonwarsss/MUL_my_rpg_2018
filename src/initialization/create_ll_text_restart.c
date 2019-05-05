/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_text.c
*/

#include <stdlib.h>
#include "my.h"

static text_t *push_ll(text_t *next, char *msg, int end, sfFont *font)
{
    text_t *tmp = malloc(sizeof(text_t));

    if (!tmp)
        return (NULL);
    tmp->msg = msg;
    tmp->len = 0;
    tmp->text = sfText_create();
    tmp->end = end;
    sfText_setFont(tmp->text, font);
    sfText_setString(tmp->text, msg);
    sfText_setPosition(tmp->text, (sfVector2f) {635, 955});
    tmp->next = next;
    return (tmp);
}

text_t *create_ll_text_restart(void)
{
    text_t *tmp = NULL;
    sfFont *font = sfFont_createFromFile("ressources/font/font.ttf");

    tmp = push_ll(tmp, "You took forces and reseted timer bar !", 0, font);
    return (tmp);
}
