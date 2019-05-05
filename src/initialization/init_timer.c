/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_timer
*/

#include <stdlib.h>
#include "my.h"

mtimer_t *init_timer(void)
{
    mtimer_t *timer = malloc(sizeof(mtimer_t));

    if (!timer)
        return (NULL);
    timer->sprite = sfSprite_create();
    timer->texture = sfTexture_createFromFile(TIMER, NULL);
    if (!timer->sprite || !timer->texture)
        return (NULL);
    timer->font = sfSprite_create();
    timer->texture_font = sfTexture_createFromFile(TIMERFONT, NULL);
    if (!timer->font || !timer->texture_font)
        return (NULL);
    sfSprite_setTexture(timer->sprite, timer->texture, sfTrue);
    sfSprite_setTexture(timer->font, timer->texture_font, sfTrue);
    timer->timer = 0;
    timer->max_time = 120;
    timer->on = 0;
    return (timer);
}
