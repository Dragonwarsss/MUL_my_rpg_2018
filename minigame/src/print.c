/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** print
*/

#include <unistd.h>
#include <stdlib.h>
#include "minigame.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    if (str == 0 || str[i] == 0)
        return (84);
    while (str[i] != 0) {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i]) {
        if (s1[i] < s2[i]) {
            return (-1);
        }
        if (s1[i] > s2[i]) {
            return (1);
        }
        i = i + 1;
    }
    return (0);
}
