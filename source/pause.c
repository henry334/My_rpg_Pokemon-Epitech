/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply **send_pause_menu(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("./ressources/pause/pause.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 44, 1080, 720});
    save[1] = NULL;
    return save;
}

text **send_pos_pause(void)
{
    text **save = malloc(sizeof(save) * 5);
    save[0] = create_text("POKEMON",
    (sfVector2f){165, 160}, 65, sfWhite);
    save[1] = create_text("BAG",
    (sfVector2f){730, 160}, 65, sfWhite);
    save[2] = create_text("SAVE",
    (sfVector2f){165, 440}, 65, sfWhite);
    save[3] = create_text("EXIT",
    (sfVector2f){730, 440}, 65, sfWhite);
    save[4] = NULL;
    return save;
}

int choose_pause(wdw * wind_struct, dsply **pause, game *games, text **which)
{
    int d = event2(wind_struct, pause, 2, 3);
    switch (d) {
    case 71:
        return (pause_left(wind_struct, pause));
    case 72:
        return (pause_right(wind_struct, pause));
    case 73:
        return (pause_up(wind_struct, pause));
    case 74:
        return (pause_down(wind_struct, pause));
    case 58:
        return enter(wind_struct, pause, games, which);
    case 36:
        return EXIT_FUNC;
    }
    return LOOP;
}

int pause_m(wdw *wind_struct, game *games)
{
    dsply **pause = send_pause_menu();
    text **which = send_pos_pause();
    int d = LOOP;
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        d = choose_pause(wind_struct, pause, games, which);
        display_sprite(pause, wind_struct, 1);
        display_text(which, wind_struct);
        if (d == EXIT_FUNC)
            break;
    }
    destroy_text(which);
    destroy_sprite(pause);
    free_double(pause);
    free_double_text(which);
    return d;
}