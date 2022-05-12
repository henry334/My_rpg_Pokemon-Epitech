/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void mooove_gd(wdw *wind_struct, dsply **games)
{
    if (wind_struct->event.key.code == wind_struct->key_up1)
        wind_struct->key_up = PRESS;
    if (wind_struct->event.key.code == wind_struct->key_left1)
        wind_struct->key_left = PRESS;
    if (wind_struct->event.key.code == wind_struct->key_down1)
        wind_struct->key_down = PRESS;
    if (wind_struct->event.key.code == wind_struct->key_right1)
        wind_struct->key_right = PRESS;
}

void mooove_bd(wdw *wind_struct, dsply **games)
{
    if (wind_struct->event.key.code == wind_struct->key_up1)
        wind_struct->key_up = UNPRESS;
    if (wind_struct->event.key.code == wind_struct->key_left1)
        wind_struct->key_left = UNPRESS;
    if (wind_struct->event.key.code == wind_struct->key_down1)
        wind_struct->key_down = UNPRESS;
    if (wind_struct->event.key.code == wind_struct->key_right1)
        wind_struct->key_right = UNPRESS;
}