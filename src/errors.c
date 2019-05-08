/*
** EPITECH PROJECT, 2019
** checking errors
** File description:
** Mai Ly lehoux
*/

#include "../include/my.h"

void print_usage(void)
{
    my_putstr("Finite runner created with CSFML.\n");
    my_putstr("USAGE\n    ./my_runner map.txt\n\n");
    my_putstr("OPTION\n    -i ");
    my_putstr("         launch the game in infinity mode.\n");
    my_putstr("    -h          ");
    my_putstr("print the usage and quit.\n\nUSER INTERACTION\n");
    my_putstr("    SPACE_KEY  jump.");
}

int manage_error(int ac)
{
    if (ac != 2) {
        my_putstr("./my_runner: bad argument:");
        my_put_nbr(ac);
        my_putstr(" given but 2 is required");
        return (EX_ERROR);
    }
    return (SUCCESS);
}

FILE *openfile(char *av)
{
    FILE *fd = fopen(av, "r");

    if (fd == NULL)
        return (NULL);
    else
        return (fd);
}
