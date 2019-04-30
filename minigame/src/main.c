/*
** EPITECH PROJECT, 2018
** display a window
** File description:
** disp
*/

#include <stdlib.h>
#include "minigame.h"

void bug_tick(t_minigame *game)
{
    if (game->bug.seconds >= 0.12) {
        sfClock_restart(game->bug.clock);
    }
     game->bug.time = sfClock_getElapsedTime(game->bug.clock);
    game->bug.seconds = game->bug.time.microseconds / 1000000.0;
    game->bug.pos.x = game->bug.pos.x + 0.09f;

    if (game->bug.pos.x > 800) {
        game->bug.pos.x = -120;
        game->bug.pos.y = rand() % 400;
    }
}

void poll_events(t_minigame *game)
{
    while (sfRenderWindow_pollEvent(game->engine.window,
                                    &game->engine.event.event)) {
        if (game->engine.event.event.type == sfEvtClosed)
            sfRenderWindow_close(game->engine.window);

        if (game->engine.event.event.type == sfEvtMouseButtonPressed) {
            check_bug_is_clicked(game);
        }
    }
}

void check_bug_is_clicked(t_minigame *game)
{
    game->engine.mouse.position =
        sfMouse_getPosition((sfWindow*) game->engine.window);
    if (game->engine.mouse.position.x > game->bug.pos.x &&
        game->engine.mouse.position.x < game->bug.pos.x + 110 &&
        game->engine.mouse.position.y > game->bug.pos.y &&
        game->engine.mouse.position.y < game->bug.pos.y + 110) {
        game->bug.pos.x = -120;
        game->bug.pos.y = rand() % 400;
        game->score.nb_score += 1;
        sfText_setString(game->score.text, int_to_text(game->score.nb_score));
    }
}

void free_game(t_minigame *game)
{
    sfRenderWindow_destroy(game->engine.window);
    sfTexture_destroy(game->engine.background.texture);
    sfSprite_destroy(game->engine.background.sprite);
    sfSound_destroy(game->sound.music);
    sfSoundBuffer_destroy(game->sound.soundbuffer);
    sfClock_destroy(game->bug.clock);
    sfSprite_destroy(game->bug.sprite);
    sfTexture_destroy(game->bug.texture);
    sfText_destroy(game->score.text);
    sfFont_destroy(game->score.font);
}

int main(int ac, char **av)
{
    t_minigame game;

    if (init_game(&game) == -1) {
        my_putstr("Could not init game\n");
        return (-1);
    }
    loop_game(&game);
    free_game(&game);
    return (0);
}
