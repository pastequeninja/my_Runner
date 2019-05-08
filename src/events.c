/*
** EPITECH PROJECT, 2019
** events called
** File description:
** Mai Ly lehoux
*/

#include "../include/my.h"

void jump_it(heroe_t *heroe)
{
    if (heroe->position.y <= 500)
        heroe->position.y = 500;
    if (heroe->rect.left >= 650) {
        heroe->bool = 0;
        heroe->clock_it = 100000;
        heroe->position.y = 630;
    }
    if (heroe->rect.left <= 550 && heroe->rect.left >= 330)
        heroe->position.y += 2;
    else if (heroe->rect.left <= 324) {
        heroe->position.y -= 2;
    }
}

void events_called(sfRenderWindow *window, sfEvent event, heroe_t *heroe)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeySpace) {
            heroe->bool = 1;
            heroe->rect.left = 110;
            heroe->clock_it = 200000;
        }
    }
}
