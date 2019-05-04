/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_text
*/

#include <stdlib.h>
#include "my.h"

void display_text(text_t *text, sfRenderWindow *window, sound_t *music)
{
    if (text->len != my_strlen(text->msg)) {
        if (sfMusic_getStatus(music->music) == sfStopped)
            sfMusic_play(music->music);
        text->msg_tmp = malloc(sizeof(char) * text->len + 1);
        text->msg_tmp = my_strncpy(text->msg_tmp, text->msg, text->len);
        sfText_setString(text->text, text->msg_tmp);
        sfRenderWindow_drawText(window, text->text, NULL);
        free(text->msg_tmp);
        text->len += 1;
        return;
    } else {
        sfText_setString(text->text, text->msg);
        sfRenderWindow_drawText(window, text->text, NULL);
        if (sfMusic_getStatus(music->music) == sfPlaying)
            sfMusic_stop(music->music);
    }
}
