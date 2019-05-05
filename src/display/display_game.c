/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_game
*/

#include <stdio.h>
#include "map.h"
#include "my.h"

void display_timer(mtimer_t *timer, sfRenderWindow *window)
{
    int width;
    float new_width;

    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->timer = sfTime_asSeconds(timer->time);
    timer->rect = sfSprite_getTextureRect(timer->font);
    if (timer->timer != 0) {
        width = ((float)timer->timer * 100.0) / (float)timer->max_time;
        timer->rect.width = (float)timer->rect.width * ((float)width / 100.0);
        sfSprite_setTextureRect(timer->sprite, timer->rect);
        sfRenderWindow_drawSprite(window, timer->font, NULL);
        sfRenderWindow_drawSprite(window, timer->sprite, NULL);
    }
}

void player_event(UNUSED game_t *game, UNUSED sfRenderWindow *window)
{
    interact(game->player, game->maps[game->map], game);
}

void display_game(game_t *game, sfRenderWindow *window)
{
    display_map(game->maps[game->map], window);
    display_player(game->player, window);
    player_event(game, window);
    if (game->text) {
        sfRenderWindow_drawSprite(window, game->utils[0]->sprite, NULL);
        display_text(game->text, window, game->sounds[3]);
    }
    if (game->timer->on)
        display_timer(game->timer, window);
}
