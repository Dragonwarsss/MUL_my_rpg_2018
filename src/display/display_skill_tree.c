/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_skill_tree
*/

#include <unistd.h>
#include "my.h"

void manage_skill_input(game_t *game, sfRenderWindow *window)
{
    sprite_t *tmp = game->skills;
    sfVector2i pm = sfMouse_getPositionRenderWindow(window);
    int level = 1;

    while (tmp) {
        if (pm.x >= tmp->pos.x &&
        pm.x <= tmp->pos.x + (tmp->rect.width * 3) &&
        pm.y >= tmp->pos.y &&
        pm.y <= tmp->pos.y + (tmp->rect.height * 3) &&
        tmp->button && tmp->rect.left == 0 &&
        game->invader->level >= level) {
            tmp->rect.left = 48;
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
            game->invader->weapons->texture = tmp->texture;
            sfSprite_setTexture(game->invader->weapons->sprite,
            tmp->texture, sfFalse);
        }
        tmp = tmp->next;
        level += 1;
    }
}

void display_skill_tree(game_t UNUSED *game, sfRenderWindow UNUSED *window)
{
    sfRenderWindow_drawText(window, game->text_level, NULL);
    show_ll_sprite(game->skills, window);
}
