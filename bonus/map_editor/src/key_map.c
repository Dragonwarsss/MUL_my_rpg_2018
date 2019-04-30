/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** key_map.c
*/

#include <SFML/Graphics.h>
#include <edit.h>

void key_map(sfEvent *event, edit_t *edit)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyP && edit->ground == 0) {
            edit->ground = 1;
            change_text(edit, "map2");
        }
        if (event->key.code == sfKeyM && edit->ground == 1) {
            edit->ground = 0;
            change_text(edit, "map1");
        }
    }
}
