/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** load_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "edit.h"
#include <my.h>

void read_maps(edit_t *edit, int fd)
{
    for (int i = 0; i != edit->width; i += 1) {
        for (int j = 0; j != edit->height; j += 1) {
            read(fd, &edit->map[i][j], sizeof(int));
        }
    }
    for (int i = 0; i != edit->width; i += 1) {
        for (int j = 0; j != edit->height; j += 1) {
            read(fd, &edit->map2[i][j], sizeof(int));
        }
    }
}

void free_maps(edit_t *edit)
{
    for (int i = 0; i != edit->width; i += 1) {
        free(edit->map[i]);
        free(edit->map2[i]);
    }
    free(edit->map);
    free(edit->map2);
}

void alloc_maps(edit_t *edit)
{
    edit->map = malloc(sizeof(int*) * edit->width);
    edit->map2 = malloc(sizeof(int*) * edit->width);

    for (int i = 0; i != edit->width; i += 1) {
        edit->map[i] = malloc(sizeof(int) * edit->height);
        edit->map2[i] = malloc(sizeof(int) * edit->height);
    }
    for (int i = 0; i != edit->width; i += 1)
        for (int j = 0; j != edit->height; j += 1) {
            edit->map[i][j] = 0;
            edit->map2[i][j] = 0;
        }
}

int load_map(edit_t *edit)
{
    int fd = open(edit->map_to_load, O_RDONLY);

    free_maps(edit);
    if (fd == -1) {
        my_puterr("map to load not found...\n");
        return (84);
    }
    read(fd, &edit->width, sizeof(int));
    read(fd, &edit->height, sizeof(int));
    alloc_maps(edit);
    read_maps(edit, fd);
    close(fd);
    my_puterr("map loaded !\n");
    return (0);
}
