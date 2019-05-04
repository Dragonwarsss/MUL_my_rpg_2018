/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** utils
*/

char *my_strncpy(char *str1, char *str2, int n)
{
    int i = 0;

    while (i != n) {
        str1[i] = str2[i];
        i += 1;
    }
    str[i] = 0;
    return (str1);
}
