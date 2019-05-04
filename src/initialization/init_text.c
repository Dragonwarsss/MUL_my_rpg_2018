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
    tmp->next = next;
    return (tmp);
}

text_t *init_text(void)
{
    text_t *tmp = NULL;
    sfFont *font = sfFont_createFromFile("ressources/font/font.ttf");

    tmp = push_ll(tmp, "You can learn new skills when you end a project.", 1, font);
    tmp = push_ll(tmp, "Press I to see your skill tree.", 0, font);
    tmp = push_ll(tmp, "You can learn skills by upgrading tools via"
    " skill tree.", 0, font);
    tmp = push_ll(tmp, "Some bugs are resistant to some tools, so use"
    " efficient tools to defeat them.", 0, font);
    tmp = push_ll(tmp, "Fight with valgring and gdb tools to defeat bugs.", 0, font);
    tmp = push_ll(tmp, "To complete projects, go to a computer a"
    " press ENTER.", 0, font);
    tmp = push_ll(tmp, "Don't waste too many time there, it increase a"
    " lot your sickness bar.", 0, font);
    tmp = push_ll(tmp, "To reset your sickness, go to the 5th floor"
    " and eat some food.", 0, font);
    tmp = push_ll(tmp, "Becareful, doing project increases your sickness,"
    " if your sickness bar is full, you loose...", 0, font);
    tmp = push_ll(tmp, "Your goal is to beat every project of the 1st"
    " year.", 0, font);
    tmp = push_ll(tmp, "Welcome to EPITECH the game !", 0, font);
    return (tmp);
}
