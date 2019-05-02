/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "my.h"

void event_handler(sfEvent *event, sfRenderWindow *window, game_t UNUSED *game)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseButtonPressed)
        exec_mouse_button_scene(game, window);
    if (event->type == sfEvtKeyPressed)
        check_key_press_scene(event, game);
}

int gameloop(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    game_t *game = init_game();

    if (!game)
        return (84);
    window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, window, game);
        select_scene(game, window);
        put_pause(game, window);
        if (game->quit)
            break;
    }
    return (0);
}

int main(int UNUSED argc, char UNUSED **argv, char **envp)
{
    int stat = 0;

    if (!envp[0])
        return (84);
    stat = gameloop();
    return (stat);
}