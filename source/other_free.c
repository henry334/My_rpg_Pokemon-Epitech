/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"

void free_inventory(dsply **items)
{
    destroy_sprite(items);
    free_double(items);
}