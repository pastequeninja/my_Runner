/*
** EPITECH PROJECT, 2019
** ddd
** File description:
** dd
*/

#include "../../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
