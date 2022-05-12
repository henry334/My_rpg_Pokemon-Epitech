/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int wait_key(wdw *wind_struct, dsply **setting_sp, int x)
{
    int p = LOOP;
    sfText_setString(wind_struct->texts[x]->txt,
    "CLICK ON A KEY");
    while (p == LOOP && sfRenderWindow_isOpen(wind_struct->window)) {
        sfRenderWindow_drawRectangleShape(wind_struct->window,
        wind_struct->squares[0]->rs, NULL);
        display_sprite(setting_sp, wind_struct, 1);
        display_text(wind_struct->texts, wind_struct);
        if (wind_struct->music_on_off == 0)
            sfRenderWindow_drawRectangleShape(wind_struct->window,
            wind_struct->squares[1]->rs, NULL);
        p = event2(wind_struct, setting_sp, 6, 3);
    }
    return p;
}

void music_switchs(wdw *wind_struct, square **squares)
{
    if (wind_struct->music_on_off == 0) {
        sfMusic_pause(wind_struct->music);
        wind_struct->music_on_off = 1;
    } else {
        sfMusic_play(wind_struct->music);
        wind_struct->music_on_off = 0;
    }
}

void change_fps_m(square **squares, wdw *wind_struct, int c)
{
    if (c == 30) {
        squares[0]->fps_m.x = 300;
        squares[0]->fps_m.y = 250;
    } else if (c == 60) {
        squares[0]->fps_m.x = 420;
        squares[0]->fps_m.y = 250;
    } else {
        squares[0]->fps_m.x = 540;
        squares[0]->fps_m.y = 250;
    }
    sfRenderWindow_setFramerateLimit(wind_struct->window, c);
    sfRectangleShape_setPosition(squares[0]->rs, squares[0]->fps_m);
}

int choose_setting(wdw *wind_struct, dsply **menu_sp)
{
    int x = event2(wind_struct, menu_sp, 1, 2);
    switch (x) {
        case 1:
            return EXIT_FUNC;
        case 2:
            music_switchs(wind_struct, wind_struct->squares);
            break;
        case 3:
            change_fps_m(wind_struct->squares, wind_struct, 30);
            break;
        case 4:
            change_fps_m(wind_struct->squares, wind_struct, 60);
            break;
        case 5:
            change_fps_m(wind_struct->squares, wind_struct, 120);
            break;
        default:
            setting_stuff(x, wind_struct, menu_sp);
    }
    return LOOP;
}

void settings(wdw *wind_struct)
{
    int p = LOOP;
    dsply **setting_sp = creat_setting();
    wind_struct->squares = create_fps_square(wind_struct);
    wind_struct->texts = creat_text_setting_key(wind_struct);
    while (p != EXIT_FUNC && sfRenderWindow_isOpen(wind_struct->window)) {
        sfRenderWindow_drawRectangleShape(wind_struct->window,
        wind_struct->squares[0]->rs, NULL);
        display_sprite(setting_sp, wind_struct, 1);
        display_text(wind_struct->texts, wind_struct);
        if (wind_struct->music_on_off == 0)
            sfRenderWindow_drawRectangleShape(wind_struct->window,
            wind_struct->squares[1]->rs, NULL);
        p = choose_setting(wind_struct, setting_sp);
        update_text(wind_struct);
    }
    wind_struct->last = wind_struct->squares[0]->fps_m;
    destroy_sprite(setting_sp);
    free_double(setting_sp);
}
