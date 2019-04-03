/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "my.h"

void event_handler(sfEvent *event, sfRenderWindow *window, game_t *g)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

int gameloop(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    game_t *g = init_game();

    if (!g)
        return (84);
    window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, window, g);
        select_scene(g, window);
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    int stat = 0;

    if (!envp[0])
        return (84);
    stat = gameloop();
    return (stat);
}
