/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "macros.h"
#include "map.h"
#include "sound.h"

#ifndef my_h_
#define my_h_

typedef struct s_game game_t;
typedef struct s_scene scene_t;
typedef struct s_sprite sprite_t;
typedef struct s_player player_t;

typedef enum scene_id {
    sc_menu = 0,
    sc_option = 1,
    sc_skill_tree = 2,
    sc_map1 = 3,
    sc_map2 = 4,
    sc_map3 = 5,
} screen_id_t;

struct s_player {
    int id;
    int scale;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f pos_map;
    player_t *next;
    player_t *prev;
};

struct s_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int button;
    void (*ptr)(game_t *game, sprite_t *spr);
    sprite_t *next;
};

struct s_scene {
    sprite_t *ll_sprite;
    player_t *player;
};

struct s_game {
    scene_t **sc;
    map_t **maps;
    player_t *player;
    screen_id_t scene;
    sound_t **sounds;
    int map;
    int quit;
    int music;
};

void my_puterr(char *str);

game_t *init_game(void);
sprite_t *create_ll_menu(void);
sprite_t *create_ll_options(void);
player_t *init_player(player_t *ptr);
sound_t **init_music(void);

void *create_ll_char(void);

void exec_mouse_button_scene(game_t *game, sfRenderWindow *window);
void check_key_press_scene(sfEvent *event, game_t *game);
void manage_menu_input(game_t *game, sfRenderWindow *window);

void put_music_or_not(game_t *game, sprite_t *spr);
void change_scene_to_play(game_t *game, sprite_t *spr);
void change_scene_to_settings(game_t *game, sprite_t *spr);
void quit_game(game_t *game, sprite_t *spr);

void select_scene(game_t *game, sfRenderWindow *window);

void draw_scene(scene_t *sc, sfRenderWindow *window);

void display_option(scene_t *sc, sfRenderWindow *window);
void display_game(game_t *game, sfRenderWindow *window);
void display_skill_tree(game_t *game, sfRenderWindow *sfWindow);
void display_menu(scene_t *sc, sfRenderWindow *window, sound_t *sound);
void display_player(player_t *player, sfRenderWindow *window);

void check_key_up(map_t *map, player_t *player, sound_t **sounds);
void check_key_down(map_t *map, player_t *player, sound_t **sounds);
void check_key_left(map_t *map, player_t *player, sound_t **sounds);
void check_key_right(map_t *map, player_t *player, sound_t **sounds);

int collide(int block);

void move_map_down(sfVector2f *offset, int tile_size, player_t *player);
void move_map_up(sfVector2f *offset, int tile_size, player_t *player);
void move_map_left(sfVector2f *offset, int tile_size, player_t *player);
void move_map_right(sfVector2f *offset, int tile_size, player_t *player);

#endif
