/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_invader
*/

#include "my.h"

void display_invader(invader_t *invader, sfRenderWindow *window)
{
    show_ll_sprite(invader->weapons, window);
    display_ennemies(invader->ennemies, window);
}
