/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"

game_t *init_game(void)
{
    game_t *g = malloc(sizeof(game_t));

    if (!g)
        return (NULL);
    return (g);
}
