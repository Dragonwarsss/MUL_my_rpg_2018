/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** map.h
*/

#include <SFML/Graphics.h>

#ifndef map_h_
#define map_h_

typedef struct s_map map_t;

struct s_map {
    int **map;
    int **map2;
    int width;
    int height;
    int scale;
    int tile_size;
    sfIntRect rect;
    sfVector2f offset;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
};

int load_map(map_t *edit, char *map);
void alloc_maps(map_t *edit);
void free_maps(map_t *edit);
void read_maps(map_t *edit, int fd);

void display_map(map_t *edit, sfRenderWindow *window);

#endif
