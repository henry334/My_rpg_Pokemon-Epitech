/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** particules.c
*/

#include "../includes/rpg.h"
#include <math.h>

void get_rand_values(int *x, int *y, sfColor *color)
{
    y -= 20 + rand() % 40;
    x -= 20 + rand() % 40;
    color->a = 255;
    color->r = 220 + rand() % 35;
    color->g = 0 + rand() % 200;
    color->b = 0;
}

void show_particle(framebuffer_t *fbuffer, sfVector2u coord, sfVector2f values,
int type)
{
    int key = rand() % 100;
    sfColor color = {0, 0, 0, 0};

    if (values.x >= pow(values.y, 2))
        return;
    if (type == 2 || type == 5)
        color = (sfColor){220 + rand() % 35, 0 + rand() % 150, 0, 0};
    if (type == 3 || type == 6)
        color = (sfColor){0, 55 + rand() % 200, 255, 0};
    if (type == 7 || type == 9)
        color = (sfColor){0, 55 + rand() % 200, 0, 0};
    if (type == 4 || type == 1)
        color = (sfColor){235 + rand() % 20, 200 + rand() % 55, 0, 0};
    if (type == 10 || type == 14 || type == 15) {
        color = (sfColor){100 + rand() % 50, 0 + rand() % 50, 175 +
        rand() % 80, 0};
    }
    if (key >= 67)
        color.a = 255;
    my_put_pixel(fbuffer, coord.x, coord.y, color);
}

void circle_particle(framebuffer_t *fbuffer, sfVector2u center, int radius,
int type)
{
    int left = center.x - radius;
    int right = left + radius * 2;
    int top = center.y - radius;
    int bottom = top + radius * 2;
    double distance = 0;

    for (int y = top; y <= bottom; ++y) {
        for (int x = left; x <= right; ++x) {
            distance = ((x-center.x)*(x-center.x))+((y-center.y)*(y-center.y));
            sfVector2u coord = {x, y};
            sfVector2f values = {distance, radius};
            show_particle(fbuffer, coord, values, type);
        }
    }
}
