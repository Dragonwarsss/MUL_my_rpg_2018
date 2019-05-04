/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** utils
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}
