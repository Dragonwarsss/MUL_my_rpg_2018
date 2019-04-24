/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** action.c
*/

#include <SFML/Graphics.h>
#include "edit.h"

void action(edit_t *edit, sfRenderWindow *window, int max_x, int max_y)
{
    sfRenderWindow_drawSprite(window, edit->bg, NULL);
    sfRenderWindow_drawText(window, edit->text, NULL);
    display_map(edit, window, edit->map);
    display_map(edit, window, edit->map2);
    select_block(edit, window);
    select_map(edit, window, max_x, max_y);
}
