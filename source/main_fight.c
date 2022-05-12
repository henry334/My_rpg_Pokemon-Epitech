/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** main_fight.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void fights(game *games, wdw *wind_struct, int x)
{
    display_text(games->attack, wind_struct);
    if (games->start == 0 && games->already_att == 0 && games->poke_life > 0) {
        fight_speed_2(games, games->pok_2, wind_struct);
        games->already_att = 1;
    }
    if (x != LOOP && x == 5 && games->poke_inventory[0][2] > 0) {
        fight_speed_1(games, games->pok_1, wind_struct);
        games->already_att = 0;
    }
    if (games->start == 1 && games->already_att == 0
    && x == 5 && games->poke_life > 0) {
        fight_speed_2(games, games->pok_2, wind_struct);
        games->already_att = 1;
    }
    games->in_combat = games->poke_life <= 0 ? 3 : 4;
}

void display_sprite_fg(dsply **main_fight, wdw *wind_struct,
dsply **poke, game *games)
{
    int z = games->z;
    update_life(games, wind_struct, games->attack, 1);
    scale_fight(wind_struct, poke, main_fight);
    sfRenderWindow_display(wind_struct->window);
    sfRenderWindow_clear(wind_struct->window, sfBlack);
    sfRenderWindow_drawSprite(wind_struct->window, main_fight[0]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, main_fight[5]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, main_fight[6]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, poke[0]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, poke[1]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, main_fight[z]->sp, NULL);
}

void main_combat(wdw *wind_struct, game *games, dsply **poke)
{
    games->already_att = 0;
    games->pok_1 = att_pok_1(games->poke_inventory[0][0]);
    games->pok_2 = att_pok_1(games->poke_att);
    if (my_strcomp(games->pok_1[0], "ERRO") == 1
    || my_strcomp(games->pok_2[0], "ERRO") == 1)
        return;
    dsply **main_fight = send_create_main_fight();
    games->attack = send_attack_temp(games->pok_1, games, games->z);
    while (sfRenderWindow_isOpen(wind_struct->window)
    && games->poke_life > 0 && games->poke_inventory[0][2] > 0) {
        int x = which_choose(wind_struct, games, main_fight);
        damage(games, 0, 6);
        damage(games, 1, 7);
        display_sprite_fg(main_fight, wind_struct, poke, games);
        if (x != LOOP && x != 5)
            games->z = get_sprite(games->z, x);
        fights(games, wind_struct, x);
    }
    free_main_fight(main_fight, games->pok_1, games->pok_2, games);
}

int before_fight(wdw *wind_struct, game *games, dsply **poke)
{
    games->start = get_start(games);
    main_combat(wind_struct, games, poke);
    if (games->in_combat == 3) {
        my_printf("You won the fight\n");
        wind_struct->money += 100;
        sfText_setString(games->money[1]->txt,
        my_intchar(wind_struct->money));
        games->poke_inventory[0][1] += 50;
        games->poke_life = 0;
        games->in_combat = 2;
    } else if (games->in_combat == 4) {
        games->in_combat = 1;
        my_printf("You loose the fight\n");
        games->poke_inventory[0][2] = 0;
    }
    return 1;
}

int inside(int zone, wdw *wind_struct, game *games, dsply **poke)
{
    switch (zone) {
    case 1:
        games->z = 1;
        return before_fight(wind_struct, games, poke);
    case 2:
        pokemon_disp(games, wind_struct);
        return 2;
    case 3:
        use_inventory(wind_struct, games);
        return 3;
    case 4:
        return 4;
    }
    return 0;
}
