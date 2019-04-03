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

    scene = 0;
    if (!g)
        return (NULL);
    g->sc = malloc(sizeof(scene_t*) * 5);
    if (!g->sc)
        return (NULL);
    for (int i = 0; i != 4; i += 1) {
        g->sc[i] = malloc(sizeof(scene_t));
        if (!g->sc[i])
            return (NULL);
    }
    g->sc[0]->ll_sprite = create_ll_menu();
    if (!g->sc[0]->ll_sprite)
        return (NULL);
    return (g);
}
