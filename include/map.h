/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** map.h
*/

#include <SFML/Graphics.h>

typedef struct s_map map_t;

struct s_map {
    int **map;
    sfSprite *spritesheet;
    sfTexture *texture;
};
