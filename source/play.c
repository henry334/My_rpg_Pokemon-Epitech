/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "./../includes/rpg.h"
#include "./../includes/print.h"

void destroy_base(game *games, wdw *wind_struct)
{
    destroy_sprite(games->game);
    free_double(games->game);
    destroy_sprite(games->inventory);
    free_double(games->inventory);
    free_double_char(wind_struct->map);
}

int choose_play(wdw *wind_struct, dsply **menu_sp, game *games)
{
    int x = event2(wind_struct, menu_sp, 1, 0);
    switch (x) {
        case 1:
            games->player = 1;
            destroy_base(games, wind_struct);
            setup_games_bg(wind_struct, games);
            return 0;
        case 2:
            games->player = 2;
            destroy_base(games, wind_struct);
            setup_games_bg(wind_struct, games);
            return 0;
        case 3:
            return LOOP;
    }
    return 1;
}

int play(wdw *wind_struct, game *games)
{
    int p = 1;
    dsply **play = send_creat_play();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(play, wind_struct, 1);
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        anime_font(wind_struct, play);
        p = choose_play(wind_struct, play, games);
        if (p != 1) {
            destroy_sprite(play);
            free_double(play);
            return p;
        }
    }
    destroy_sprite(play);
    free_double(play);
    return LOOP;
}