/*
** EPITECH PROJECT, 2018
** proto
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define SUCCESS 0
#define EX_ERROR 84
#define READ_SIZE 1
#define LOSE 1

struct obstacles
{
    sfVector2f pos_obs;
    sfTexture *texture;
    sfSprite *sprite;
    struct obstacles *next;
    struct obstacles *prev;
};

struct backgrounds
{
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfSprite *sprite_2;
    sfVector2f position;
    sfVector2f position_2;
    struct backgrounds *next;
    struct backgrounds *prev;
};

struct score
{
    sfText *text;
    sfFont *font;
    sfVector2f position;
    int clock_s;
    int score_t;
};

struct heroe
{
    int mode;
    int clock_it;
    int bool;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
};

typedef struct obstacles obs_t;
typedef struct score score_t;
typedef struct backgrounds backgrounds_t;
typedef struct heroe heroe_t;
score_t *score(void);
void display_score(score_t *, sfRenderWindow *);
score_t *score(void);
char *transform_nbr(int);
int nbr_lengh(int);
void display_caisse(obs_t *, sfRenderWindow *);
void obstacles_moves(sfClock *, sfRenderWindow *, obs_t *);
int check_collision(obs_t *, heroe_t *);
int my_strlen(char *);
char *my_revstr(char *);
void my_putstr(char const *);
int my_strcmp(char *, char const *);
sfTexture *fill_texture(int);
void my_putchar(char);
void print_int_minim(void);
int my_put_nbr(int);
backgrounds_t *fill_backgrounds(void);
sfVideoMode pixels_mode(void);
void jump_it(heroe_t *);
heroe_t *fill_heroe(void);
void print_usage(void);
int manage_error(int);
FILE *openfile(char *);
void launch_game(FILE *, sfRenderWindow *, sfMusic *, heroe_t *);
void play_game(sfRenderWindow *, sfClock *, heroe_t *, obs_t *);
obs_t *begin_return(obs_t *);
int hitbox(obs_t *, heroe_t *);
void destroy_elements(heroe_t *, backgrounds_t *, sfMusic *, sfRenderWindow *);
int check_str(char *);
int count_obs(char *);
obs_t *fill_ll_obs_2(char *, obs_t *, int);
obs_t *fill_ll_obs(char *, int, obs_t *);
obs_t *manage_map(FILE *);
heroe_t *move_heroe(heroe_t *, sfRenderWindow *, sfClock *);
void events_called(sfRenderWindow *, sfEvent, heroe_t *);
void move_backgrounds(sfRenderWindow *, backgrounds_t *);

#endif
