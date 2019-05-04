/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** initialize music
*/

#include <stdlib.h>
#include "my.h"

sound_t **init_music(void)
{
    sound_t **sound = malloc(sizeof(sound_t*) * 4);

    if (!sound)
        return (NULL);
    for (int i = 0; i != 3; i += 1) {
        sound[i] = malloc(sizeof(sound_t));
        if (!sound[i])
            return (NULL);
    }
    sound[0]->music = sfMusic_createFromFile("ressources/sound/menu_theme.ogg");
    sound[1]->music = sfMusic_createFromFile("ressources/sound/walk.ogg");
    sound[2]->music = sfMusic_createFromFile("ressources/sound/collide.ogg");
    sound[3] = NULL;
    if (!sound[0]->music || !sound[1]->music || !sound[2]->music) {
        my_puterr("Missing ressources in sound/\n");
        return (NULL);
    }
    sfMusic_setLoop(sound[0]->music, sfTrue);
    sfMusic_play(sound[0]->music);
    return (sound);
}
