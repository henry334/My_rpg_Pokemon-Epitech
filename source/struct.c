/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** usage.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int setup_games_bg(wdw *wind_struct, game *games)
{
    char *pth = my_strdup(get_sp(games->player, 1));
    int m = get_chars[games->sv_map].ba;
    char *s = readfile(get_bck[m].map);
    if (my_strcomp(s, "error") == 1)
        return 84;

    wind_struct->map = my_split(s, "\n", -1);
    games->game = send_creat_game(pth, m);
    games->inventory = send_creat_inventory();
    change_rect(games, games->value);
    free(s);
    free(pth);
    return 0;
}

wdw keys(wdw wind_struct)
{
    wind_struct.back_menu = 0;
    wind_struct.money = 500;
    wind_struct.s_l = 0;
    wind_struct.s_u = 0;
    wind_struct.s_r = 0;
    wind_struct.s_d = 0;
    wind_struct.pos_y = 366;
    wind_struct.pos_x = 529;
    wind_struct.key_up1 = 73;
    wind_struct.key_right1 = 72;
    wind_struct.key_down1 = 74;
    wind_struct.key_left1 = 71;
    wind_struct.key_up = UNPRESS;
    wind_struct.key_right = UNPRESS;
    wind_struct.key_down = UNPRESS;
    wind_struct.key_left = UNPRESS;
    wind_struct.key_inventory = 8;
    wind_struct.key_poked = 15;
    return wind_struct;
}

wdw windows(void)
{
    wdw wind_struct;
    wind_struct.done_tuto = 0;
    wind_struct.ph = 0;
    wind_struct.music_on_off = 0;
    wind_struct.clock = sfClock_create();
    wind_struct.which = -1;
    wind_struct.lock = 0;
    wind_struct.scene = 0;
    wind_struct.last = (sfVector2f){420, 250};
    sfVideoMode video_mode = {1080, 720, 64};
    wind_struct.window = sfRenderWindow_create(video_mode,
    "rpg", sfClose | sfResize,  NULL);
    sfRenderWindow_setFramerateLimit(wind_struct.window, 60);
    wind_struct.msc_cm = sfMusic_createFromFile("ressources/music/fight.ogg");
    wind_struct.music = sfMusic_createFromFile("ressources/music/song.ogg");
    return keys(wind_struct);
}

game sec_g(game games)
{
    games.arceus = create_arceus();
    games.clock = sfClock_create();
    games.arceus_disp = 0;
    games.charizard = creat_charizard();
    games.quest = create_quest();
    games.vld_quest = quest_valide();
    return games;
}

game gammmmme(void)
{
    game games;
    games.l = 0;
    games.t = 0;
    games.value = 0;
    games.player = 1;
    games.max_l = 4064;
    games.max_t = 3155;
    games.sv_map = 0;
    games.ba_save = -1;
    games.is_speaking = -1;
    games.poke_att = 0;
    games.damage = 0;
    games.damage_2 = 0;
    games.in_combat = 0;
    games.speak = creat_speak();
    games.z = 0;
    games.beat_arceus = 0;
    return sec_g(games);
}