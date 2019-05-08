/*
** EPITECH PROJECT, 2019
** collisions
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"

void display_caisse(obs_t *obs, sfRenderWindow *window)
{
    obs = begin_return(obs);
    while (obs->next != NULL) {
        if (obs->pos_obs.x < 1920) {
            sfSprite_setPosition(obs->sprite, obs->pos_obs);
            sfSprite_setTexture(obs->sprite, obs->texture, sfFalse);
            sfRenderWindow_drawSprite(window, obs->sprite, NULL);
            obs = obs->next;
        }
        else
            obs = obs->next;
    }
}

void obstacles_moves(sfClock *clock, sfRenderWindow *window, obs_t *obs)
{
    obs = begin_return(obs);
    if (sfClock_getElapsedTime(clock).microseconds > 10000) {
        while (obs->next != NULL) {
            obs->pos_obs.x -= 4;
            obs = obs->next;
        }
        obs->pos_obs.x -= 60;
    }
    display_caisse(obs, window);
}

int check_collision(obs_t *obs, heroe_t *heroe)
{
    if (heroe->position.x >= obs->pos_obs.x && \
    heroe->position.x <= obs->pos_obs.x) {
        if (heroe->position.y + 110 >= obs->pos_obs.y)
            return (LOSE);
    }
    return (0);
}

void play_game(sfRenderWindow *window, sfClock *clock, \
heroe_t *heroe, obs_t *obs)
{
    sfEvent event;

    obstacles_moves(clock, window, obs);
    heroe = move_heroe(heroe, window, clock);
    events_called(window, event, heroe);
}

int hitbox(obs_t *obs, heroe_t *heroe)
{
    obs = begin_return(obs);
    while (obs->next != NULL) {
        if (check_collision(obs, heroe) == LOSE)
            return (LOSE);
        else
            obs = obs->next;
    }
    return (0);
}
