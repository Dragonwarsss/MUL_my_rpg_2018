/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** print_help
*/

#include "my.h"

void print_help(void)
{
    my_printf("Map editor using tiling map\n\n"
              "USAGE\n"
              "./map_editor\t\tHEIGHT WIDTH [OPTIONS] PATTERN\n"
              "exemple:\t\t./map_editor 50 50 -l test_map -c confs/conf.2\n\n"
              "OPTIONS\n"
              " -w\t\t\tchange width of tiles\n"
              " -h\t\t\tchange height of tiles\n"
              " -l\t\t\tload a map and edit it\n"
              " -s\t\t\tcreate a new map and save it with the choosen name\n"
              " -c\t\t\tload a personnal conf file\n\n"
              "USER INTERACTIONS\n"
              "  DIRECTIONAL_ARROWS\tchange focused block.\n"
              "  LEFT_CLICK\t\tplace a block where the mouse is.\n"
              "  KEY B\t\t\tmove map at left\n"
              "  KEY N\t\t\tmove map at right\n");
}
