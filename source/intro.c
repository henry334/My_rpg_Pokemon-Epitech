/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** create_intro.c
*/

#include "./../includes/rpg.h"
#include "./../includes/print.h"

void anime(wdw *wind_struct, dsply **intro)
{
    if (intro[1]->rect.top == 1071) {
        intro[1]->rect.top = 0;
    }
    if (intro[0]->rect.left == 10800) {
        intro[0]->rect.left = 0;
        intro[0]->rect.top += 720;
    }
}

void anime_intro(wdw *wind_struct, dsply **intro, int c)
{
    if (c == 2 || wind_struct->second > 0.05) {
            intro[0]->rect.left += 1080;
            intro[1]->rect.top += 51;
            anime(wind_struct, intro);
        if (intro[0]->rect.left == 9720 && intro[0]->rect.top == 3600)
            intro[0]->rect = (sfIntRect){0, 0, 1080, 720};
        sfClock_restart(wind_struct->clock);
    }
}

int choose_intro(wdw *wind_struct, dsply **intro)
{
    int x = event2(wind_struct, intro, 0, 0);
    switch (x) {
        case LOOP:
            return LOOP;
        default:
            return 0;
    }
}

int intro(wdw *wind_struct)
{
    dsply **intro = send_intro();
    int d = LOOP;
    int c = 0;
    for (c; sfRenderWindow_isOpen(wind_struct->window); c++) {
        wind_struct->scene = INTRO;
        sfSprite_setScale(intro[2]->sp, (sfVector2f){0.5, 0.5});
        display_sprite(intro, wind_struct, 1);
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        anime_intro(wind_struct, intro, c);
        if ((d = choose_intro(wind_struct, intro)) != LOOP)
            break;
    }
    destroy_sprite(intro);
    free_double(intro);
    sfRenderWindow_clear(wind_struct->window, sfBlack);
    return 0;
}