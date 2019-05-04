/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** start_clock
*/

#include "my.h"

void start_clock(mtimer_t *timer)
{
    timer->clock = sfClock_create();
    timer->on = 1;
}
