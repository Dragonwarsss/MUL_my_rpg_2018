/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** save.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "edit.h"
#include "my.h"

static void write_maps(edit_t *edit, int fd)
{
    for (int i = 0; i != edit->width; i += 1)
        for (int j = 0; j != edit->height; j += 1)
            write(fd, &edit->map[i][j], sizeof(int));
    for (int i = 0; i != edit->width; i += 1)
        for (int j = 0; j != edit->height; j += 1)
            write(fd, &edit->map2[i][j], sizeof(int));
}

void save(edit_t *edit, __attribute__((unused))sfRenderWindow *window)
{
    char *str = NULL;
    int fd = open(edit->map_to_save, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    my_printf("Would you like to save the map ? (Y/N)");
    str = gnl(0);
    while (1) {
        if (str[0] == 'Y') {
            write(fd, &edit->height, sizeof(int));
            write(fd, &edit->width, sizeof(int));
            write_maps(edit, fd);
            free(str);
            break;
        }
        else if (str[0] == 'N') {
            free(str);
            break;
        }
        free(str);
        str = gnl(0);
    }
    close(fd);
    free_everything(edit, window);
}
