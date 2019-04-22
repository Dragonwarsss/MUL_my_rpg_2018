/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my.h
*/

#ifndef my_h_
#define my_h_

#include "macros.h"
#include <SFML/Graphics.h>

typedef struct game_s game_t;
typedef struct scene_s scene_t;
typedef struct sprite_s sprite_t;
typedef enum scene_id_e screen_id_t;

struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int button;
    void (*ptr)(game_t **game);
    sprite_t *next;
};

enum scene_id_e {
    sc_menu,
    sc_skill_tree,
};

struct scene_s {
    sprite_t *ll_sprite;
};

struct game_s {
    scene_t **sc;
    screen_id_t scene;
};

game_t *init_game(void);
sprite_t *create_ll_menu(void);

void change_scene_to_play(game_t **game);
void change_scene_to_settings(game_t **game);

void select_scene(game_t *game, sfRenderWindow *window);

void display_skill_tree(game_t *game, sfRenderWindow *sfWindow);
void display_menu(scene_t *sc, sfRenderWindow *window);

#endif
