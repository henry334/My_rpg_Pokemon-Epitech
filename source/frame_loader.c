/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** draw_particles.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc((width * height) * sizeof(sfUint8) * 4);
    sfColor empty = {0, 0, 0, 0};
    fill_screen(framebuffer, empty);
    return framebuffer;
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color)
{
    if (y >= 1080 || x >= 1920)
        return;
    framebuffer->pixels[(y * framebuffer->width + x) * 4] = color.r;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
}

void fill_screen(framebuffer_t *framebuffer, sfColor color)
{
    int width = framebuffer->width;
    int height = framebuffer->height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x)
            my_put_pixel(framebuffer, x, y, color);
    }
}
