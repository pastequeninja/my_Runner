/*
** EPITECH PROJECT, 2018
** compare 2 chains
** File description:
** Mai Ly Lehoux
*/

#include "../../include/my.h"

int my_strcmp(char *str, char const *compare)
{
    int i = 0;
    int point = 0;

    while (str[i] != '\0') {
        if (compare[i] == '\0')
            return (1);
        if (str[i] == compare[i])
            point++;
        i++;
    }
    if (point == i)
        return (0);
    return (1);
}
