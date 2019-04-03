/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my.h
*/

#include <SFML/Graphics.h>

#ifndef my_h_
#define my_h_

typedef struct s_game game_t;
typedef struct s_scene scene_t;
typedef struct s_sprite sprite_t;

struct s_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int button;
    void (*ptr)(void);
    sprite_t *next;
};

struct s_scene {
    sprite_t *ll_sprite;
};

struct s_game {
    scene_t **sc;
    int scene;
};

game_t *init_game(void);
sprite_t *create_ll_menu(void);

void change_scene_to_play(void);
void change_scene_to_settings(void);

void select_scene(game_t *g, sfRenderWindow *window);

void display_menu(scene_t *sc, sfRenderWindow *window);

int scene;

#endif
