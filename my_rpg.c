/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** code.c
*/

#include "./includes/rpg.h"
#include "./includes/print.h"

void display_fbuffer(framebuffer_t *fbuff, sfRenderWindow *window)
{
    sfTexture* texture = sfTexture_create(1920, 1080);
    sfSprite* sprite = sfSprite_create();

    sfTexture_updateFromPixels(texture, fbuff->pixels,
    1920, 1080, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void display_game(wdw *wind_struct, game *games)
{
    display_sprite(games->game, wind_struct, 1);
    if (games->sv_map == 13 && games->beat_arceus == 0) {
        sfRenderWindow_drawSprite(wind_struct->window,
        games->arceus[games->arceus_disp]->sp, NULL);
        arceus_disp(games);
    }
    if (games->is_speaking != -1) {
        games->speak[0]->vect = (sfVector2f){games->game[1]->vect.x + 37,
        games->game[1]->vect.y - 20};
        display_sprite(games->speak, wind_struct, 0);
        if (wind_struct->event.type == sfEvtKeyPressed &&
            wind_struct->event.key.code == 4) {
            check_interaction(games, wind_struct);
        }
    }
}

int my_rpg(wdw *wind_struct, game *games)
{
    int x;
    wind_struct->ph = MAIN_GAME;

    while (sfRenderWindow_isOpen(wind_struct->window)
        && wind_struct->back_menu == 0) {
        games->time = sfClock_getElapsedTime(games->clock);
        games->second = games->time.microseconds / 1000000.0;
        display_game(wind_struct, games);
        if (games->sv_map == 0)
            display_sprite(games->charizard, wind_struct, 0);
        x = event2(wind_struct, games->game, 2, 0);
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        moove(wind_struct, games, x);
    }
    return 0;
}

void my_window(wdw *wind_struct)
{
    game games = gammmmme();
    add_item(&games, -1);
    add_pokemon_inventory(&games, -1);
    games.money = creat_money(my_intchar(wind_struct->money));
    setup_games_bg(wind_struct, &games);
    if (menu(wind_struct, &games) == EXIT_FUNC) {
        des_game(&games);
        return;
    } else if(wind_struct->done_tuto == 0)
        add_pokemon_inventory(&games, my_tuto(wind_struct));
    wind_struct->done_tuto = 1;
    my_rpg(wind_struct, &games);
    sfClock_destroy(games.clock);
    des_game(&games);
    if (wind_struct->back_menu == 1) {
        reset_to(wind_struct);
        my_window(wind_struct);
    }
}

int main(int argv, char **argc)
{
    time_t t;
    srand((unsigned) time(&t));
    if (argv > 1 && (argc[1][0] == '-' && argc[1][1] == 'h')) {
        usage();
        return 0;
    }
    wdw wind_struct = windows();
    sfMusic_play(wind_struct.music);
    sfMusic_setLoop(wind_struct.music, sfTrue);
    if (argv > 1 && my_strcomp("-n", argc[1]) == 1) {
        wind_struct.music_on_off = 1;
        sfMusic_stop(wind_struct.music);
    }
    intro(&wind_struct);
    my_window(&wind_struct);
    dest(&wind_struct);
    return 0;
}
