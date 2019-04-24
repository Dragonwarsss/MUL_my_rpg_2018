/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** set_struct
*/

#include <stdlib.h>
#include "edit.h"
#include "my.h"

void fill_map(int **map, int height, int width)
{
    for (int i = 0; i != width; i += 1)
        for (int j = 0; j != height; j += 1)
            map[i][j] = 0;
}

void set_struct2(edit_t *edit)
{
    edit->font = sfSprite_create();
    edit->font_t = sfTexture_createFromFile("assets/font.png", NULL);
    sfSprite_setTexture(edit->font, edit->font_t ,sfTrue);
    edit->pos_font = (sfVector2f) {470, 1010};
    sfSprite_setPosition(edit->font, edit->pos_font);
    edit->block = 0;
    edit->map2 = malloc(sizeof(int*) * edit->width);
    for (int i = 0; i != edit->width; i += 1)
        edit->map2[i] = malloc(sizeof(int) * edit->height);
    fill_map(edit->map2, edit->height, edit->width);
    edit->ground = 0;
    edit->bg = sfSprite_create();
    edit->bg_t = sfTexture_createFromFile("assets/bg.png", NULL);
    sfSprite_setTexture(edit->bg, edit->bg_t, sfTrue);
    edit->text = sfText_create();
    edit->font_text = sfFont_createFromFile("font/font.ttf");
    sfText_setFont(edit->text, edit->font_text);
    sfText_setString(edit->text, "map1");
    edit->map_to_save = "map";
    edit->map_to_load = NULL;
}

void set_struct(edit_t *edit, char **av)
{
    edit->tile_size = 70;
    edit->height = my_atoi(av[1]);
    edit->width = my_atoi(av[2]);
    edit->name_sheet = "assets/spritesheet.png";
    edit->texture = sfTexture_createFromFile(edit->name_sheet, NULL);
    edit->sprite = sfSprite_create();
    sfSprite_setTexture(edit->sprite, edit->texture, sfTrue);
    sfSprite_setScale(edit->sprite, (sfVector2f) {1, 1});
    edit->map = malloc(sizeof(int*) * edit->width);
    for (int i = 0; i != edit->width; i += 1)
        edit->map[i] = malloc(sizeof(int) * edit->height);
    fill_map(edit->map, edit->height, edit->width);
    edit->pos = (sfVector2f) {0, 0};
    edit->rect = (sfIntRect) {0, 0, edit->tile_size, edit->tile_size};
    edit->pos_bar = (sfVector2f) {200, 1010};
    edit->rect_bar = (sfIntRect) {0, 0, 1050, 70};
    edit->selected = sfSprite_create();
    edit->selected_t = sfTexture_createFromFile("assets/selected.png", NULL);
    sfSprite_setTexture(edit->selected, edit->selected_t, sfTrue);
    edit->pos_selected = (sfVector2f) {200, 1010};
    set_struct2(edit);
}
