/*
** EPITECH PROJECT, 2019
** manage heroe
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"

heroe_t *fill_heroe(void)
{
    heroe_t *heroe = malloc(sizeof(heroe_t));

    heroe->rect.width = 110;
    heroe->rect.height = 150;
    heroe->position.x = 60;
    heroe->position.y = 630;
    heroe->bool = 0;
    heroe->clock_it = 100000;
    heroe->sprite = sfSprite_create();
    heroe->texture = sfTexture_createFromFile("sprites/jeux twi/men.png", NULL);

    return (heroe);
}

heroe_t *move_heroe(heroe_t *heroe, sfRenderWindow *window, sfClock *clock)
{
    if (sfClock_getElapsedTime(clock).microseconds > heroe->clock_it) {
        heroe->rect.left += 108;
        sfClock_restart(clock);
    }
    if (heroe->rect.left >= 864 && heroe->bool == 0) {
        heroe->rect.left = 0;
    }
    if (heroe->bool == 1)
        jump_it(heroe);
    sfSprite_setPosition(heroe->sprite, heroe->position);
    sfSprite_setTextureRect(heroe->sprite, heroe->rect);
    sfSprite_setTexture(heroe->sprite, heroe->texture, sfFalse);
    sfRenderWindow_drawSprite(window, heroe->sprite, NULL);

    return (heroe);
}
