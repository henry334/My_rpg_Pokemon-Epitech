/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void free_tuto(dsply **tuto, text **dialogue)
{
    destroy_sprite(tuto);
    free_double(tuto);
    destroy_text(dialogue);
    free_double_text(dialogue);
}

void free_pokemon_disp(dsply **bg, dsply **poke, text **info_poke, dsply **x)
{
    destroy_sprite(bg);
    destroy_sprite(poke);
    destroy_sprite(x);
    free_double(bg);
    free_double(poke);
    free_double(x);
    destroy_text(info_poke);
    free_double_text(info_poke);
}

void free_fight_f(dsply **poke, dsply **fight, text **f)
{
    destroy_text(f);
    destroy_sprite(poke);
    destroy_sprite(fight);
    free_double(poke);
    free_double(fight);
    free_double_text(f);
}

void destroy_load_save(dsply **btn, text **num)
{
    destroy_sprite(btn);
    destroy_text(num);
    free_double(btn);
    free_double_text(num);
}

void free_main_fight(dsply **main_fight, char **pok_1, char **pok_2, game *g)
{
    destroy_sprite(main_fight);
    free_double(main_fight);
    free_double_char(pok_1);
    free_double_char(pok_2);
    destroy_text(g->attack);
    free_double_text(g->attack);
}