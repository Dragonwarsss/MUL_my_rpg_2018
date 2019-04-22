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

typedef struct s_game game_t;
typedef struct s_scene scene_t;
typedef struct s_sprite sprite_t;

typedef enum scene_id {
    sc_menu,
    sc_skill_tree,
} screen_id_t;

struct s_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int button;
    void (*ptr)(game_t *game);
    sprite_t *next;
};

struct s_scene {
    sprite_t *ll_sprite;
};

struct s_game {
    scene_t **sc;
    screen_id_t scene;
};

game_t *init_game(void);
sprite_t *create_ll_menu(void);

void exec_mouse_button_scene(game_t *game, sfRenderWindow *window);
void manage_menu_input(game_t *game, sfRenderWindow *window);

void change_scene_to_play(game_t *game);
void change_scene_to_settings(game_t *game);

void select_scene(game_t *game, sfRenderWindow *window);

void display_skill_tree(game_t *game, sfRenderWindow *sfWindow);
void display_menu(scene_t *sc, sfRenderWindow *window);

#endif
