/*
** EPITECH PROJECT, 2018
** revstr.c
** File description:
** reverse str
*/

#include "../../include/my.h"
#include <stdio.h>

char *my_revstr(char *str)
{
    int first = 0;
    int last = 0;
    char temp;

    while (str[last] != '\0')
        last++;
    last = last - 1;
    if (my_strlen(str) > 0) {
        while (first <= last) {
            temp = str[last];
            str[last] = str[first];
            str[first] = temp;
            first++;
            last--;
	}
    }
    return (str);
}
