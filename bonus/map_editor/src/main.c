/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** map_editor
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "edit.h"
#include "my.h"

void event_handler(sfEvent *event, sfRenderWindow *window, edit_t *edit)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyRight && edit->pos_selected.x < 1700) {
            edit->pos_selected.x += edit->tile_size * edit->scale;
            edit->block += 100;
        }
        if (event->key.code == sfKeyLeft && edit->pos_selected.x > 200) {
            edit->pos_selected.x -= edit->tile_size * edit->scale;
            edit->block -= 100;
        }
        if (event->key.code == sfKeyUp && edit->rect_bar.top > 0) {
            edit->rect_bar.top -= (edit->tile_size);
            edit->block -= 1;
        }
        if (event->key.code == sfKeyDown && edit->rect_bar.top < 420) {
            edit->rect_bar.top += (edit->tile_size);
            edit->block += 1;
        }
        if (event->key.code == sfKeyD) {
            move_map_right(&edit->offset, edit->tile_size);
            edit->x_offset += 1;
        }
        if (event->key.code == sfKeyQ) {
            move_map_left(&edit->offset, edit->tile_size);
            edit->x_offset -= 1;
        }
        if (event->key.code == sfKeyZ) {
            move_map_up(&edit->offset, edit->tile_size);
            edit->y_offset -= 1;
        }
        if (event->key.code == sfKeyS) {
            move_map_down(&edit->offset, edit->tile_size);
            edit->y_offset += 1;
        }
    }
    key_map(event, edit);
}

int get_param(int ac, char **av)
{
    if (ac == 1)
        return (1);
    if (ac == 2 && my_strcomp(av[1], "-h")) {
        print_help();
        return (1);
    }
//    if (my_atoi(av[1]) < 16 || my_atoi(av[2]) < 16)
//        return (84);
    return (0);
}

int edit(__attribute__((unused))int ac, char **av, int max_x, int max_y)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    edit_t *edit = malloc(sizeof(edit_t));
    int stat = 0;

    stat = init(ac, av, edit);
    if (stat != 0)
        return (stat);
    window = sfRenderWindow_create(mode, "map_editor", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 24);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            if (sfRenderWindow_hasFocus(window))
                event_handler(&event, window, edit);
        action(edit, window, max_x, max_y);
    }
    save(edit, window);
    return (0);
}

int main(__attribute__((unused))int ac, char **av)
{
    int stat;

    stat = get_param(ac, av);
    if (stat == 84)
        return (84);
    if (stat == 0)
        stat = edit(ac, av, atoi(av[1]), atoi(av[2]));
    return (stat);
}
