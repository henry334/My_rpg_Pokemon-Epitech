/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** navy.h
*/

#ifndef RUNNER_H_
    #define RUNNER_H_
    #include "struct.h"
    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <time.h>
    #include <SFML/System/Types.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

    #define INTRO 1
    #define LOOP 49
    #define EXIT_FUNC 50
    #define EXIT_ERROR "error"
    #define PRESS 100
    #define UNPRESS 101
    #define MAIN_GAME 48
    #define ITEM1 0
    #define ITEM2 1
    #define PERCENTAGEFIGHT 48

void usage(void);
int intro(wdw *);
int intro(wdw *);
char *nmm(int code);
int random_poke(int l);
void des_game(game *games);
int get_start(game *games);
char *readfile(char *path);
int get_place(int n, int xp);
void sort_array(game *games);
int num_of_item(game *games);
int my_tuto(wdw *wind_struct);
int get_type_pok(char *attack);
char *get_level(int xp, int num);
void settings(wdw *wind_struct);
int num_of_pokemon(game *games);
char *get_sp(int code, int type);
char *my_concate_b(char *s, ...);
int add_item(game *games, int n);
void my_window(wdw *wind_struct);
int conv(wdw *wind_struct, int n);
void update_text(wdw *wind_struct);
void free_double(dsply **temp);
void free_double_char(char **temp);
void free_double_text(text **temp);
void heal_poke(int c, game *games);
void poke_moove(game *games, int z);
void upmp(game *games, int y, int x);
void display_invpoke_backend(game *games);
int get_key(wdw *wind_struct, int op);
void change_rect(game *games, int mode);
int play(wdw *wind_struct, game *games);
int menu(wdw *wind_struct, game *games);
int load(wdw *wind_struct, game *games, char *path);
int shop(wdw *wind_struct, game *games);
void arene(game *games, wdw *wind_struct);
void update_rect_m(game *games, int mode);
int saves(wdw *wind_struct, game *games, char *path);
int pause_m(wdw *wind_struct, game *games);
void add_map(wdw *wind_struct, char **temp);
void music_fight(wdw *wind_struct, int mode);
void reset_to(wdw *wind_struct);
void pharmacy(game *games, wdw *wind_struct);
int pause_up(wdw *wind_struct, dsply **pause);
void all_moove(wdw *wind_struct, game *games);
int add_pokemon_inventory(game *games, int n);
int moove(wdw *wind_struct, game *games, int x);
void mooove_gd(wdw *wind_struct, dsply **games);
void mooove_bd(wdw *wind_struct, dsply **games);
int pause_down(wdw *wind_struct, dsply **pause);
void arceus_fight(game *games, wdw *wind_struct);
void check_interaction(game *games, wdw *wind_struct);
int pause_left(wdw *wind_struct, dsply **pause);
int choose_poke(wdw *wind_struct, dsply **tuto);
void pokemon_disp(game *games, wdw *wind_struct);
int pause_right(wdw *wind_struct, dsply **pause);
void anime_tuto(wdw *wind_struct, dsply **intro);
void up_key(wdw *wind_struct, game *games, int x);
void free_fight_f(dsply **poke, dsply **fight, text **f);
void display_prtcl(wdw *wind_struct, int type, sfVector2f pos);
void free_main_fight(dsply **main_fight, char **pok_1, char **pok_2, game *g);
void use_inventory(wdw *wind_struct, game *games);
int setup_games_bg(wdw *wind_struct, game *games);
void left_key(wdw *wind_struct, game *games, int x);
void down_key(wdw *wind_struct, game *games, int x);
void right_key(wdw *wind_struct, game *games, int x);
int check_size(char *string, char *parse, int size);
int enter(wdw *wind_struct, dsply **pause, game *games, text **which);
int enter_2(wdw *wind_struct, dsply **pause, game *games, text **which);
void display_pokemon(wdw *wind_struct, dsply **x, dsply **bg, dsply **poke);
int collision(wdw *wind_struct, game *game, int y, int x);
int wait_key(wdw *wind_struct, dsply **setting_sp, int x);
void scale_fight(wdw *wind_struct, dsply **poke, dsply **fight);
void destroy_load_save(dsply **btn, text **num);
int lets_use_items(game *games, wdw *wind_struct, int x);
void manager_charizard(game *games, int mode, int y, int x);
int save_and_load(game *games, wdw *wind_struct, int mode);
int fight_speed_1(game *games, char **pok_1, wdw *wind_struct);
int fight_speed_2(game *games, char **pok_2, wdw *wind_struct);
void setting_stuff(int x, wdw *wind_struct, dsply **menu_sp);
int play_check(wdw *wind_struct, dsply **struc, int st, int op);
void update_life(game *games, wdw *wind_struct, text **attack, int mode);
void free_pokemon_disp(dsply **bg, dsply **poke, text **info_poke, dsply **x);
dsply **send_manual(void);
int manual(wdw *wind_struct);

//struct
wdw windows(void);
game gammmmme(void);
dsply **send_intro(void);
wdw follow(wdw wind_struct);
text **send_text_tuto(void);
dsply **send_creat_tuto(void);
dsply **send_creat_inventory(void);

//fight
dsply **send_create_fight(void);
dsply **send_create_intro_fight(void);
int intro_fight(wdw *wind_struct, game *games , int poke_at);
void main_combat(wdw *wind_struct, game *games, dsply **poke);
dsply **send_create_main_fight(void);
text **send_attack_temp(char **pok_1, game *games, int z);
int inside(int zone, wdw *wind_struct, game *games, dsply **poke);
int do_we_fight(game *games, wdw *wind_struct);
void scale_fight(wdw *wind_struct, dsply **poke, dsply **fight);
char **att_pok_1(int id_1);
text **fight_text(game *games);
int which_choose(wdw *wind_struct, game *games, dsply **fight);
int get_sprite(int z, int x);
dsply **dsply_poke(game *games, int poke_at);
text *type_of_attack(game *games, int num, text *temp, sfVector2f pos);
void damage(game *games, int num, int where);
text **send_attack_temp_2(text **save, char **pok_1, game *games, int z);
double make_damage(game *games, char **pok_1, int z);
double make_damage_on_us(game *games, char **pok_2);
int random_poke(int l);

//display
void display_sprite(dsply **struc, wdw *wind_struct, int d);
void display_text(text **struc, wdw *wind_struct);
void display_invisible(dsply **invisible, wdw *wind_struct);
void display_icone(dsply **invisible, wdw *wind_struct);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color);
void display_quest(game *games, wdw *wind_struct);
void fill_screen(framebuffer_t *framebuffer, sfColor color);
void display_fbuffer(framebuffer_t *fbuff, sfRenderWindow *window);
void circle_particle(framebuffer_t *fbuffer, sfVector2u center, int radius,
int type);

//destroy
void dest(wdw *windo_struct);
void destroy_sprite(dsply **struct1);
void destroy_text(text **struct1);
void destroy_square(square **struct1);
void destroy_base(game *games, wdw *wind_struct);
void free_tuto(dsply **tuto, text **dialogue);
void free_inventory(dsply **items);

//create
text **creat_dlg(int x);
dsply **creat_text(void);
dsply **creat_shop(void);
dsply **quest_valide(void);
text **create_quest(void);
dsply **creat_speak(void);
text **creat_num(char *s);
text **creat_money(char *s);
dsply **creat_setting(void);
dsply **creat_bg_poke(void);
text **creat_end_tuto(void);
dsply **create_arceus(void);
dsply **creat_x(game *games);
void arceus_disp(game *games);
dsply **creat_pharmacy(void);
dsply **creat_charizard(void);
dsply **send_creat_play(void);
dsply **send_creat_menu(void);
dsply **creat_pokemon(game *games);
text **creat_poke_text(game *games);
dsply **creat_inventory_item(game *games);
dsply **creat_setting_two(dsply **making);
dsply **send_creat_game(char *player, int c);
square **create_fps_square(wdw *wind_struct);
text **creat_text_setting_key(wdw *wind_struct);
text *create_text(char *string, sfVector2f pos, int size, sfColor color);
square *create_square(sfColor color, sfVector2f pos, sfVector2f size);
dsply *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect);

//event
int event2(wdw *wind_struct, dsply **meny_sp, int st, int op);
void anime_font(wdw *wind_struct, dsply **intro);

#endif/*RUNNER_H_*/
