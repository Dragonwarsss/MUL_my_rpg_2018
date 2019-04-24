/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** free_everything
*/

#include <stdlib.h>
#include "edit.h"

void free_everything(edit_t *edit, sfRenderWindow *window)
{
    for (int i = 0; i != edit->width; i += 1) {
        free(edit->map[i]);
        free(edit->map2[i]);
    }
    free(edit->map);
    free(edit->map2);
    sfSprite_destroy(edit->sprite);
    sfSprite_destroy(edit->selected);
    sfSprite_destroy(edit->font);
    sfSprite_destroy(edit->bg);
    sfTexture_destroy(edit->texture);
    sfTexture_destroy(edit->selected_t);
    sfTexture_destroy(edit->font_t);
    sfTexture_destroy(edit->bg_t);
    sfFont_destroy(edit->font_text);
    sfText_destroy(edit->text);
    sfRenderWindow_destroy(window);
}
