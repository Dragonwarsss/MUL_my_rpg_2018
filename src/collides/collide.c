/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** collide
*/

#include <stdio.h>

int collide(int block)
{
    if (block >= 800 && block <= 804)
        return (0);
    if (block >= 900 && block <= 904)
        return (0);
    if (block >= 1000 && block <= 1004)
        return (0);
    if (block >= 1100 && block <= 1104)
        return (0);
    if (block >= 1200 && block <= 1204)
        return (0);
    if (block >= 1300 && block <= 1304)
        return (0);
    if (block == 1600 || block == 1601 || block == 1700 || block == 1701)
        return (0);
    if (block == 1800 || block == 1801 || block == 1900 || block == 1901)
        return (0);
    if (block == 0 || block == 208 || block == 209)
        return (0);
    return (1);
}
