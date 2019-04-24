/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_puterr
*/

#include <unistd.h>

static int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i += 1);
    return (i);
}

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
