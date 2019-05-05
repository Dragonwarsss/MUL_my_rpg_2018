/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_ennemies.c
*/

#include <stdlib.h>
#include "my.h"

void display_ennemies(ennemies_t *ennemies, sfRenderWindow *window)
{
    ennemies_t *tmp = ennemies;

    for (; tmp; tmp = tmp->next) {
        sfSprite_move(tmp->sprite,
        (sfVector2f) {rand() % 10 - 5, rand() % 10 - 5});
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    }
}
