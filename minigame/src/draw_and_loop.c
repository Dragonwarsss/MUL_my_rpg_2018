/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** draw and loop
*/

#include "minigame.h"

void loop_game(t_minigame *game)
{
    while (sfRenderWindow_isOpen(game->engine.window)) {
        draw_game(game);
        bug_tick(game);
        poll_events(game);
    }
}

void draw_game(t_minigame *game)
{
    sfRenderWindow_drawSprite(game->engine.window,
    game->engine.background.sprite, NULL);
    sfSprite_setTextureRect(game->bug.sprite, game->bug.rect);
    sfSprite_setPosition(game->bug.sprite, game->bug.pos);
    sfRenderWindow_drawSprite(game->engine.window, game->bug.sprite, NULL);
    sfRenderWindow_drawText(game->engine.window, game->score.text, 0);
    sfRenderWindow_display(game->engine.window);
}
