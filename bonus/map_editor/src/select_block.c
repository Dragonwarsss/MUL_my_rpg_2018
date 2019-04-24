/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** select_block.c
*/

#include <SFML/Graphics.h>
#include "edit.h"

void select_block(edit_t *edit, sfRenderWindow *window)
{
    sfSprite_setPosition(edit->sprite, edit->pos_bar);
    sfSprite_setPosition(edit->selected, edit->pos_selected);
    sfSprite_setTextureRect(edit->sprite, edit->rect_bar);
    sfRenderWindow_drawSprite(window, edit->font, NULL);
    sfRenderWindow_drawSprite(window, edit->sprite, NULL);
    sfRenderWindow_drawSprite(window, edit->selected, NULL);
}
