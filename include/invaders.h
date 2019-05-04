/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** invaders.h
*/

#ifndef INVADERS_H_
#define INVADERS_H_

typedef struct s_inv inv_t;
typedef struct s_ennemies ennemies_t;

struct s_ennemies {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    ennemies_t *next;
    ennemies_t *prev;
};

struct s_inv {
    ennemies_t *enn;
};

#endif
