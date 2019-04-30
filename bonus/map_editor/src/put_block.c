/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** put_block.c
*/

#include <SFML/Graphics.h>
#include "edit.h"
#include "my.h"

void put_block(edit_t *edit, sfRenderWindow *window, int **map, int max_x, int max_y)
{
    sfVector2i pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pos = get_pos_map(edit, window);
        if (pos.x >= max_x || pos.y >= max_y);
        else {
            map[pos.y][pos.x - edit->x_offset] = edit->block;
            printf("put: %d\n", edit->block);
        }
    }
}
