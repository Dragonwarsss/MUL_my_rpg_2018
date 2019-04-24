/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** load_conf
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "edit.h"
#include "my.h"

int read_name_conf(int const fd, edit_t *edit)
{
    char *str = NULL;

    str = gnl(fd);
    for (int j = 0; j != 5; j += 1)
        str++;
    str++;
    edit->name_sheet = str;
    sfTexture_destroy(edit->texture);
    edit->texture = sfTexture_createFromFile(edit->name_sheet, NULL);
    sfSprite_setTexture(edit->sprite, edit->texture, sfTrue);
    edit->rect.width = edit->tile_size;
    edit->rect.height = edit->tile_size;
    if (!edit->texture) {
        my_puterr("ERROR: spritesheet name not found\n");
        return (84);
    }
    return (0);
}

int read_conf_file(int const fd, edit_t *edit)
{
    char *str = NULL;

    str = gnl(fd);
    for (int j = 0; j != 10; j += 1)
        str++;
    edit->tile_size = my_atoi(str);
    //
    str = gnl(fd);
    for (int j = 0; j != 6; j += 1)
        str++;
    edit->scale = my_atoi(str);
    sfSprite_setScale(edit->sprite, (sfVector2f) {edit->scale, edit->scale});
    //
    str = gnl(fd);
    for (int j = 0; j != 8; j += 1)
        str++;
    edit->rect.height = my_atoi(str);
    str = gnl(fd);
    for (int j = 0; j != 7; j += 1)
        str++;
    edit->rect.width = my_atoi(str);
    return (read_name_conf(fd, edit));
}

int load_conf(char *conf, edit_t *edit)
{
    int stat = 0;
    int fd = open(conf, O_RDONLY);
    char *base_conf = "TILE_SIZE: 70\nHEIGHT: 1050"
        "\nWIDTH: 490\nNAME: assets/spritesheet.png\n";

    if (fd == -1) {
        my_puterr("conf file not found...\n");
        my_puterr("creating conf file...\n");
        fd = open("conf", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        write(fd, base_conf, my_strlen(base_conf));
        close(fd);
        open("conf", O_RDONLY);
    }
    my_puterr("reading conf file...\n");
    stat = read_conf_file(fd, edit);
    if (stat != 0)
        return (stat);
    return (0);
}
