/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** move_map.c
*/

#include "edit.h"

void move_map_left(sfVector2f *offset, int tile_size)
{
    (*offset).x -= tile_size;
}

void move_map_right(sfVector2f *offset, int tile_size)
{
    (*offset).x += tile_size;
}

void move_map_up(sfVector2f *offset, int tile_size)
{
    (*offset).y -= tile_size;
}

void move_map_down(sfVector2f *offset, int tile_size)
{
    (*offset).y += tile_size;
}
