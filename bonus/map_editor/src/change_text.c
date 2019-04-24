/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** change_text.c
*/

#include <SFML/Graphics.h>
#include "edit.h"

void change_text(edit_t *edit, char const *str)
{
    sfText_setString(edit->text, str);
}
