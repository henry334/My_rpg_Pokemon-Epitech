/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void setting_stuff(int x, wdw *wind_struct, dsply **m)
{
    switch (x) {
        case 7:
            wind_struct->key_left1 = wait_key(wind_struct, m, 0);
            break;
        case 8:
            wind_struct->key_right1 = wait_key(wind_struct, m, 1);
            break;
        case 9:
            wind_struct->key_up1 = wait_key(wind_struct, m, 2);
            break;
        case 10:
            wind_struct->key_down1 = wait_key(wind_struct, m, 3);
            break;
        case 11:
            wind_struct->key_inventory = wait_key(wind_struct, m, 4);
            break;
        case 12:
            wind_struct->key_poked = wait_key(wind_struct, m, 5);
            break;
    }
}

void update_text(wdw *wind_struct)
{
    sfText_setString(wind_struct->texts[0]->txt,
    nmm(wind_struct->key_left1));
    sfText_setString(wind_struct->texts[1]->txt,
    nmm(wind_struct->key_right1));
    sfText_setString(wind_struct->texts[2]->txt,
    nmm(wind_struct->key_up1));
    sfText_setString(wind_struct->texts[3]->txt,
    nmm(wind_struct->key_down1));
    sfText_setString(wind_struct->texts[4]->txt,
    nmm(wind_struct->key_inventory));
    sfText_setString(wind_struct->texts[5]->txt,
    nmm(wind_struct->key_poked));
}
