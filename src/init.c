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
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->scene = 0;
    game->sc = malloc(sizeof(scene_t*) * 5);
    if (!game->sc)
        return (NULL);
    for (int i = 0; i != 4; i += 1) {
        game->sc[i] = malloc(sizeof(scene_t));
        if (!game->sc[i])
            return (NULL);
    }
    game->sc[0]->ll_sprite = create_ll_menu();
    if (!game->sc[0]->ll_sprite)
        return (NULL);
    return (game);
}
