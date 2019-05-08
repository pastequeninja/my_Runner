/*
** EPITECH PROJECT, 2018
** runner Mai Ly Lehoux
** File description:
** 20/01
*/

#include "../include/my.h"

sfVideoMode pixels_mode(void)
{
    sfVideoMode pixels = {1920, 1080, 32};

    return (pixels);
}

void destroy_elements(heroe_t *her, backgrounds_t *back, \
sfMusic *mus, sfRenderWindow *w)
{
    sfMusic_destroy(mus);
    sfSprite_destroy(her->sprite);
    sfSprite_destroy(back->sprite);
    sfSprite_destroy(back->sprite_2);
    sfTexture_destroy(back->texture);
    sfTexture_destroy(her->texture);
    sfRenderWindow_destroy(w);
}

obs_t *begin_return(obs_t *obs)
{
    while (obs->prev != NULL)
        obs = obs->prev;
    return (obs);
}

void launch_game(FILE *fd, sfRenderWindow *window, sfMusic *music, \
heroe_t *heroe)
{
    sfClock *clock = sfClock_create();
    backgrounds_t *background = fill_backgrounds();
    obs_t *obs = manage_map(fd);
    score_t *sc = score();

    sfMusic_play(music);
    sfRenderWindow_setFramerateLimit(window, 130);
    while (sfRenderWindow_isOpen(window)) {
        if (hitbox(obs, heroe) == LOSE) {
            break;
        }
        move_backgrounds(window, background);
        display_score(sc, window);
        play_game(window, clock, heroe, obs);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    destroy_elements(heroe, background, music, window);
}

int main(int ac, char **av)
{
    FILE *fd;
    heroe_t *heroe = fill_heroe();
    sfMusic *music = sfMusic_createFromFile("sprites/jeux twi/music.ogg");
    sfRenderWindow *window = sfRenderWindow_create(pixels_mode(), "my_runner", \
    sfResize | sfClose, NULL);

    if (manage_error(ac) == EX_ERROR)
        return (EX_ERROR);
    if (my_strcmp(av[1], "-h") == 0)
        print_usage();
    if ((fd = openfile(av[1])) == NULL)
        return (EX_ERROR);
    launch_game(fd, window, music, heroe);
    fclose(fd);
    return (SUCCESS);
}
