/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_player
*/

#include <SFML/Graphics.h>
#include "my.h"

void display_player(player_t *player, sfRenderWindow *window)
{
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}
