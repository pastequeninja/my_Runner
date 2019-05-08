/*
** EPITECH PROJECT, 2019
** manage backrounds and parallax
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"

sfTexture *fill_texture(int i)
{
    if (i == 3)
        return (sfTexture_createFromFile("sprites/jeux twi/1.png", NULL));
    if (i == 2)
        return (sfTexture_createFromFile("sprites/jeux twi/2.png", NULL));
    if (i == 1)
        return (sfTexture_createFromFile("sprites/jeux twi/0.png", NULL));
    else
        return (sfTexture_createFromFile("sprites/jeux twi/3.png", NULL));
}

backgrounds_t *fill_backgrounds_2(backgrounds_t *backgrounds_l, int i)
{
    backgrounds_l->texture = fill_texture(i);
    backgrounds_l->position.x = 0;
    backgrounds_l->position.y = 0;
    backgrounds_l->rect.width = 1920;
    backgrounds_l->rect.height = 1080;
    backgrounds_l->sprite = sfSprite_create();
    backgrounds_l->sprite_2 = sfSprite_create();
    backgrounds_l->position_2.x = 1920;
    backgrounds_l->position_2.y = 0;

    return (backgrounds_l);
}

backgrounds_t *fill_backgrounds(void)
{
    backgrounds_t *backgrounds_l = malloc(sizeof(backgrounds_t));

    if (backgrounds_l == NULL)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        if (i == 0)
            backgrounds_l->prev = NULL;
        backgrounds_l = fill_backgrounds_2(backgrounds_l, i);
        if (i == 3)
            break;
        backgrounds_l->next = malloc(sizeof(backgrounds_t));
        backgrounds_l->next->prev = backgrounds_l;
        backgrounds_l = backgrounds_l->next;
    }
    backgrounds_l->next = NULL;
    return (backgrounds_l);
}

void move_backgrounds(sfRenderWindow *window, backgrounds_t *backgrounds)
{
    float a = 0;

    while (backgrounds->prev != NULL)
        backgrounds = backgrounds->prev;
    for (;(backgrounds); backgrounds = backgrounds->next) {
        backgrounds->position.x = backgrounds->position.x - a;
        backgrounds->position_2.x = backgrounds->position_2.x - a;
        if (backgrounds->position.x <= -1920)
            backgrounds->position.x = 1920;
        if (backgrounds->position_2.x <= -1920)
            backgrounds->position_2.x = 1920;
        sfSprite_setPosition(backgrounds->sprite, backgrounds->position);
        sfSprite_setPosition(backgrounds->sprite_2, backgrounds->position_2);
        sfSprite_setTexture(backgrounds->sprite, backgrounds->texture, sfFalse);
        sfSprite_setTexture(backgrounds->sprite_2, \
        backgrounds->texture, sfFalse);
        sfRenderWindow_drawSprite(window, backgrounds->sprite, NULL);
        sfRenderWindow_drawSprite(window, backgrounds->sprite_2, NULL);
        a += 1;
    }
}
