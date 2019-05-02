/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** sound.h
*/

#include <SFML/Audio.h>

#ifndef SOUND_H_
#define SOUND_H_

typedef struct s_sound sound_t;

struct s_sound {
    sfMusic *music;
};

#endif
