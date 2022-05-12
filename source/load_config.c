/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int error_hand(char **temp, int size_o, int size_t, char *p)
{
    int l = my_twod_size(temp);
    if (l != size_o)
        return 84;
    for (int c = 0; temp[c] != NULL && size_t != -1; c++) {
        if (check_size(temp[c], p, size_t) == 1) {
            return 84;
        }
    }
    return 0;
}

void load_player_two(wdw *wind_struct, game *games, char **s)
{
    games->ba_save = my_charint(my_split(s[5], ",", -1)[1]);
    destroy_base(games, wind_struct);
    setup_games_bg(wind_struct, games);
    change_rect(games, games->value);
    games->game[1]->vect.y = my_charint(my_split(s[0], ",", -1)[0]);
    games->game[1]->vect.x = my_charint(my_split(s[0], ",", -1)[1]);
    games->t = my_charint(my_split(s[2], ",", -1)[0]);
    games->l = my_charint(my_split(s[2], ",", -1)[1]);
    wind_struct->pos_y = my_charint(my_split(s[4], ",", -1)[0]);
    wind_struct->pos_x = my_charint(my_split(s[4], ",", -1)[1]);
    games->game[0]->rect.left = my_charint(my_split(s[1], ",", -1)[1]);
    games->game[0]->rect.top = my_charint(my_split(s[1], ",", -1)[0]);
    games->charizard[0]->vect.y = my_charint(my_split(s[7], ",", -1)[0]);
    games->charizard[0]->vect.x = my_charint(my_split(s[7], ",", -1)[1]);
    games->beat_arceus = my_charint(my_split(s[8], ",", -1)[0]);
    games->max_l = get_bck[get_chars[games->sv_map].ba].ml;
    games->max_t = get_bck[get_chars[games->sv_map].ba].mt;
    free_double_char(s);
}

int load_player(wdw *wind_struct, game *games, char *path)
{
    char *temp = my_conc("./save/player", path, 127);
    char *fl = readfile(temp);
    if (my_strcomp(fl, "error") == 1)
        return 84;
    char **s = my_split(fl, "P!", -1);
    s = my_split(s[0], ":", -1);
    if (error_hand(s, 9, 2, ",") == 84)
        return 84;
    wind_struct->done_tuto = my_charint(my_split(s[3], ",", -1)[0]);
    games->player = my_charint(my_split(s[3], ",", -1)[1]);
    games->sv_map = my_charint(my_split(s[5], ",", -1)[0]);
    games->value = my_charint(my_split(s[6], ",", -1)[0]);
    destroy_text(games->money);
    free_double_text(games->money);
    wind_struct->money = my_charint(my_split(s[6], ",", -1)[1]);
    games->money = creat_money(my_intchar(wind_struct->money));
    load_player_two(wind_struct, games, s);
    free(fl);
    free(temp);
    return 0;
}

int load_inventory(game *games, char *fl)
{
    char **s = my_split(fl, "\n", -1);
    char **temp = my_split(s[0], ",", -1);
    if (my_twod_size(s) != 2 || error_hand(temp, 19, -1, ",") == 84)
        return 84;
    for (int c = 0; c < 19; c++)
        games->inventorys[c] = my_charint(temp[c]);
    s = my_split(s[1], ":", -1);
    if (error_hand(s, 5, 3, ",") == 84)
        return 84;
    for (int c = 0; c < 5; c++) {
        temp = my_split(s[c], ",", -1);
        games->poke_inventory[c][0] = my_charint(temp[0]);
        games->poke_inventory[c][1] = my_charint(temp[1]);
        games->poke_inventory[c][2] = my_charint(temp[2]);
    }
    free_double_char(temp);
    free_double_char(s);
    return 0;
}

int load(wdw *wind_struct, game *games, char *path)
{
    int x = load_player(wind_struct, games, path);
    char *p = my_conc("./save/inventory", path, 127);
    char *fl = readfile(p);
    if (my_strcomp(fl, "error") == 1) {
        my_printf("CANT READ INVENTORY FILE\n");
        return LOOP;
    }
    int z = load_inventory(games, fl);
    free(fl);
    free(p);
    if (x == 84 || z == 84) {
        my_printf("CANT LOAD, ERROR IN CONFIG FILE\n");
        return LOOP;
    }
    my_printf("Loaded\n");
    free(path);
    return 1;
}
