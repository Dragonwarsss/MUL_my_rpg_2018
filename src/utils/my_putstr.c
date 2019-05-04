/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** utils
*/

#include <unistd.h>

int my_strlen(char *str);

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
