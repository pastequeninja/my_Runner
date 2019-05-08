/*
** EPITECH PROJECT, 2019
** score
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"

int nbr_lengh(int clock)
{
    int lengh = 1;

    while (clock > 9) {
        clock /= 10;
        lengh++;
    }
    return (lengh);
}

char *transform_nbr(int clock)
{
    int i = 0;
    int power = 1;
    char *res = malloc(sizeof(char) * (nbr_lengh(clock) + 1));

    if (res == NULL)
        return (NULL);
    while (clock / power > 9)
        power += 10;
    while (power != 1) {
        res[i] = clock / power + '0';
        clock %= power;
        power /= 10;
        i++;
    }
    res[i] = clock + '0';
    res[i + 1] = '\0';
    return (res);
}
void display_score(score_t *score, sfRenderWindow *window)
{
    if (score->score_t < 90) {
        score->clock_s += 1;
        if (score->clock_s > 9) {
            score->score_t += 1;
            score->clock_s = 0;
        }
        sfText_setPosition(score->text, score->position);
        sfText_setString(score->text, transform_nbr(score->score_t));
        sfRenderWindow_drawText(window, score->text, NULL);
    }
    else
        return;
}

score_t *score(void)
{
    score_t *score = malloc(sizeof(score_t));

    score->text = sfText_create();
    score->font = sfFont_createFromFile("sprites/jeux twi/font.ttf");
    score->position.x = 950;
    score->position.y = 40;
    score->clock_s = 0;
    score->score_t = 0;
    sfText_setFont(score->text, score->font);
    sfText_setColor(score->text, sfBlack);
    return (score);
}
