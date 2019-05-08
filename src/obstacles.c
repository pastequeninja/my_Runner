/*
** EPITECH PROJECT, 2019
** manage obstacles
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"

int check_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '2')
            return (1);
        i++;
    }
    return (0);
}

int count_obs(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '2')
            count++;
        i++;
    }
    return (count);
}

obs_t *fill_ll_obs_2(char *str, obs_t *obs, int nbr_obs)
{
    int i = 0;
    int count = 0;

    obs = begin_return(obs);
    while (count < nbr_obs) {
        if (str[i] == '2') {
            obs->pos_obs.y = 660;
            obs->pos_obs.x = i * 100;
            obs->sprite = sfSprite_create();
            obs->texture = sfTexture_createFromFile \
            ("sprites/jeux twi/caisse.png", NULL);
            count++;
        }
        if (str[i] == '2' && obs->next) {
            obs = obs->next;
            obs->pos_obs.x = i * 100;
        }
        i++;
    }
    return (obs);
}

obs_t *fill_ll_obs(char *str, int nbr_obs, obs_t *obs)
{
    int i = 0;

    while (i < nbr_obs) {
        if (i == 0)
            obs->prev = NULL;
        if (i == nbr_obs - 1)
            break;
        obs->next = malloc(sizeof(obs_t));
        obs->next->prev = obs;
        obs = obs->next;
        i++;
    }
    obs->next = NULL;
    obs = fill_ll_obs_2(str, obs, nbr_obs);
    return (obs);
}

obs_t *manage_map(FILE *fd)
{
    size_t size;
    char *str = 0;
    int nbr_obs;
    obs_t *obs = malloc(sizeof(obs_t));

    if (obs == NULL)
        return (NULL);
    getline(&str, &size, fd);
    while (check_str(str) == 0)
        getline(&str, &size, fd);
    nbr_obs = count_obs(str);
    obs = fill_ll_obs(str, nbr_obs, obs);
    return (obs);
}
