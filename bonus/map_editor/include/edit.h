/*
** EPITECH PROJECT, 2018
** map_editor
** File description:
** my_runner
*/

#include <SFML/Graphics.h>

#ifndef EDIT_H_
#define EDIT_H_

typedef struct s_edit edit_t;

struct s_edit {
    char *map_to_load;
    char *map_to_save;
    char *name_sheet;
    int **map;
    int **map2;
    sfSprite *bg;
    sfTexture *bg_t;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *selected;
    sfTexture *selected_t;
    sfSprite *font;
    sfTexture *font_t;
    sfIntRect rect;
    sfIntRect rect_bar;
    sfVector2f pos;
    sfVector2f pos_bar;
    sfVector2f pos_selected;
    sfVector2f pos_font;
    sfFont *font_text;
    sfText *text;
    int width;
    int height;
    int block;
    int ground;
    int tile_size;
    int scale;
    int x_offset;
    int y_offset;
    sfVector2f offset;
};

void display_map(edit_t *edit, sfRenderWindow *window, int **map);
void move_map_right(sfVector2f *offset, int tile_size);
void move_map_left(sfVector2f *offset, int tile_size);
void move_map_up(sfVector2f *offset, int tile_size);
void move_map_down(sfVector2f *offset, int tile_size);

void select_block(edit_t *edit, sfRenderWindow *window);
void put_block(edit_t *edit, sfRenderWindow *window, int **map);
sfVector2i get_pos_map(edit_t *edit, sfRenderWindow *window);
void select_map(edit_t *edit, sfRenderWindow *window);
void key_map(sfEvent *event, edit_t *edit);

void print_help(void);

int load_conf(char *conf, edit_t *edit);
int load_map(edit_t *edit);
int read_conf_file(int const fd, edit_t *edit);
int read_name(int const fd, edit_t *edit);

int get_opt(int ac, char **av, edit_t *edit, char *opt);
void set_struct(edit_t *edit, char **av);
int init(int ac, char **av, edit_t *edit);
void alloc_maps(edit_t *edit);

void free_everything(edit_t *edit, sfRenderWindow *window);
void read_maps(edit_t *edit, int fd);
void free_maps(edit_t *edit);
void alloc_maps(edit_t *edit);

void action(edit_t *edit, sfRenderWindow *window);

void change_text(edit_t *edit, char const *str);

void save(edit_t *edit, sfRenderWindow *window);

#endif
