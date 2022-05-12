/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** print.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>

struct get_back {
    char code;
    char *path;
    char *map;
    sfVector2f pos;
    sfVector2f scl;
    sfIntRect rect;
    int mt;
    int ml;
};

struct get_dlg {
    char *path;
    int size;
};

struct get_pers {
    char code;
    sfVector2f v_pe;
    int way;
    int x;
    int y;
};

struct get_chars {
    char n;
    int ba;
    int pe;
    int out_ba;
    int out_pe;
};

struct get_pokemon_bck {
    char *sprite_b;
    sfIntRect rectb;
};

static struct get_pokemon_bck get_poke_bck[] = {
        {"ressources/pokemon/back/pikachu.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/charmander_back.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/pidgey.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/gastly.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/gible.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/raichu.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/charizard.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/pidgeotto.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/gengar.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/garchomp.png",
        (sfIntRect){0, 0, 80, 80}},
        {"ressources/pokemon/back/arceus.png",
        (sfIntRect){0, 0, 80, 80}},
};

struct get_pokemon {
    int id;
    char *name;
    int attack;
    int life;
    int defense;
    int speed;
    int attack_spe;
    char *sprite_o;
    sfIntRect rect;
};

struct type {
    int id;
    char *type;
    int dam;
};

static struct type get_type[] = {
    {0, "Acier", 17},
    {1, "Combat", 8},
    {2, "Dragon", 2},
    {3, "Eau", 5},
    {4, "Électrik", 3},
    {5, "Feu", 17},
    {6, "Glace", 16},
    {7, "Insecte", 17},
    {8, "Normale", 17},
    {9, "Plante", 17},
    {10, "Poison", 9},
    {11, "Psy", 1},
    {12, "Roche", 5},
    {13, "Sol", 4},
    {14, "Spectre", 14},
    {15, "Ténèbres", 14},
    {16, "Vol", 1},
};

static struct get_pokemon get_poke[] = {
        {0, "Pikachu", 73, 134, 48, 90, 50,
        "ressources/pokemon/front/pikachu-f.png", (sfIntRect){0, 0, 96, 96}},
        {1, "Salameche", 84, 142, 50, 65, 60,
        "ressources/pokemon/front/charmander.png", (sfIntRect){0, 0, 96, 96}},
        {2, "Roucool", 74, 157, 43, 56, 35,
        "ressources/pokemon/front/pidgey.png", (sfIntRect){0, 0, 96, 96}},
        {3, "Fantominus", 100, 117, 42, 80, 100,
        "ressources/pokemon/front/gastly.png", (sfIntRect){0, 0, 96, 96}},
        {4, "Griknot", 95, 143, 65, 42, 40,
        "ressources/pokemon/front/gible-f.png", (sfIntRect){0, 0, 96, 96}},
        {5, "Raichu", 110, 292, 90, 110, 90,
        "ressources/pokemon/front/raichu.png", (sfIntRect){0, 0, 80, 80}},
        {6, "Dracofeu", 120, 334, 100, 100, 109,
        "ressources/pokemon/front/charizard.png", (sfIntRect){0, 0, 80, 80}},
        {7, "Roucarnage", 110, 325, 105, 101, 70,
        "ressources/pokemon/front/pidgeotto.png", (sfIntRect){0, 0, 94, 92}},
        {8, "Ectoplasma", 170, 280, 70, 110, 130,
        "ressources/pokemon/front/gengar.png", (sfIntRect){0, 0, 96, 96}},
        {9, "Carchacrok", 140, 324, 100, 102, 80,
        "ressources/pokemon/front/garchomp-f.png", (sfIntRect){0, 0, 85, 84}},
        {10, "Arceus", 225, 450, 120, 200, 200,
        "ressources/pokemon/front/arceus.png", (sfIntRect){0, 0, 96, 96}},
};

static struct get_dlg get_dg[] = {
        {"dlg1.txt", 20},
        {"dlg2.txt", 20},
        {"dlg3.txt", 6},
};

static struct get_chars get_chars[] = {
        {'a', 0, 0},
        {'b', 2, 2, 0, 0},
        {'d', 1, 1, 0},
        {'c', 2, 3, 0},
        {'e', 2, 2, 3, 4},
        {'f', 2, 2, 4, 5},
        {'g', 2, 2, 5, 6},
        {'h', 6, 7, 9, 10},
        {'i', 2, 2, 7, 8},
        {'j', 10, 11, 11, 12},
        {'k', 12, 13, 16, 17},
        {'l', 14, 15, 15, 16},
        {'m', 8, 9, 17, 18},
        {'n', 18, 19, 0, 0},
        {'o', 8, 20, 0, 0},
        {'p', 17, 21, 0, 0},
        {-1},
};

static struct get_pers get_perso[] = {
        {'a', (sfVector2f){540, 350}, 0, 529, 366},
        {'b', (sfVector2f){650, 225}, 0, 49, 2},
        {'c', (sfVector2f){670, 460}, 3, 60, 44},
        {'d', (sfVector2f){649, 244}, 0, 56, 8},
        {'e', (sfVector2f){540, 350}, 0, 563, 371},
        {'f', (sfVector2f){540, 350}, 0, 560, 406},
        {'g', (sfVector2f){540, 350}, 0, 542, 387},
        {'h', (sfVector2f){475, 450}, 3, 26, 39},
        {'i', (sfVector2f){540, 350}, 0, 318, 395},
        {'j', (sfVector2f){545, 520}, 3, 67, 67},
        {'k', (sfVector2f){540, 350}, 0, 55, 398},
        {'l', (sfVector2f){525, 465}, 0, 46, 44},
        {'m', (sfVector2f){540, 350}, 0, 52, 382},
        {'n', (sfVector2f){149, 640}, 3, 24, 198},
        {'o', (sfVector2f){149, 640}, 3, 24, 198},
        {'p', (sfVector2f){540, 660}, 3, 32, 104},
        {'q', (sfVector2f){540, 350}, 0, 92, 353},
        {'r', (sfVector2f){540, 350}, 0, 137, 331},
        {'s', (sfVector2f){540, 350}, 0, 24, 70},
        {'t', (sfVector2f){540, 650}, 0, 45, 96},
        {'u', (sfVector2f){557, 142}, 0, 70, 4},
        {'v', (sfVector2f){314, 49}, 0, 52, 1},
        {-1},
};

static struct get_back get_bck[] = {
    {'a', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){3260, 2418, 4490, 3436}, 3155, 4064},
    {'b', "./ressources/map_game/all/pokemon_map1_v3.png",
    "./ressources/map_game/m_col/houseA.txt", (sfVector2f){193, 50},
    (sfVector2f){2.59, 2.59}, (sfIntRect){0, 0, 272, 224}, 0, 0},
    {'c', "./ressources/map_game/all/pokemon_map1_v4.png",
    "./ressources/map_game/m_col/houseB.txt", (sfVector2f){190, 50},
    (sfVector2f){2.59, 2.59}, (sfIntRect){0, 0, 272, 224}, 0, 0},
    {'e', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt", (sfVector2f){0, 0},
    (sfVector2f){2.59, 2.59},
    (sfIntRect){3467, 2448, 4490, 3436}, 3155, 4064},
    {'f', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt", (sfVector2f){0, 0},
    (sfVector2f){2.59, 2.59},
    (sfIntRect){3452, 2658, 4490, 3436}, 3155, 4064},
    {'g', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt", (sfVector2f){0, 0},
    (sfVector2f){2.59, 2.59},
    (sfIntRect){3341, 2544, 4490, 3436}, 3155, 4064},
    {'h', "./ressources/map_game/all/pokemon_map1_v7.png",
    "./ressources/map_game/m_col/Shop.txt", (sfVector2f){120, -130},
    (sfVector2f){2.59, 2.59},
    (sfIntRect){0, 0, 448, 328}, 0, 0},
    {'i', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){1994, 2595, 4490, 3436}, 3155, 4064},
    {'j', "./ressources/map_game/all/pokemon_map1_v10.png",
    "./ressources/map_game/m_col/ligue.txt", (sfVector2f){-45, -95},
    (sfVector2f){2.59, 2.59},
    (sfIntRect){0, 0, 448, 328}, -10, 100},
    {'k', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){413, 2610, 4490, 3436}, 3155, 4064},
    {'l', "./ressources/map_game/all/pharmacy.png",
    "./ressources/map_game/m_col/pharmacy",
    (sfVector2f){90, 30}, (sfVector2f){2.59, 2.59},
    (sfIntRect){0, 0, 344, 240}, 0, 0},
    {'m', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){395, 2517, 4490, 3436}, 3155, 4064},
    {'n', "./ressources/map_game/all/tnl.png",
    "./ressources/map_game/m_col/tnl.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){79, 706, 815, 1088}, 712, 295},
    {'o', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){3260, 2418, 4490, 3436}, 3155, 4064},
    {'p', "./ressources/map_game/all/arn.png",
    "./ressources/map_game/m_col/arn.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.27, 2.27},
    (sfIntRect){-60, 120, 376, 560}, 0, 0},
    {'q', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){635, 2340, 4490, 3436}, 3155, 4064},
    {'r', "./ressources/map_game/pokemon_map.png",
    "./ressources/map_game/m_col/map.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){908, 2211, 4490, 3436}, 3155, 4064},
    {'s', "./ressources/map_game/all/tnl.png",
    "./ressources/map_game/m_col/tnl.txt",
    (sfVector2f){0, 0}, (sfVector2f){2.59, 2.59},
    (sfIntRect){79, 115, 815, 1088}, 712, 295},
    {'t', "./ressources/map_game/all/arc.png",
    "./ressources/map_game/m_col/arc_col.txt",
    (sfVector2f){35, -220}, (sfVector2f){2.59, 2.59},
    (sfIntRect){0, 0, 416, 432}, 0, 0},
    {-1, NULL},
};

struct chars_name {
    int code;
    char *name;
};

static struct chars_name get_name[] = {
        {71, "KEY LEFT"},
        {72, "KEY RIGHT"},
        {73, "KEY UP"},
        {74, "KEY DOWN"},
        {0, "A"},
        {25, "Z"},
        {4, "E"},
        {17, "R"},
        {19, "T"},
        {24, "Y"},
        {20, "U"},
        {8, "I"},
        {14, "O"},
        {15, "P"},
        {16, "Q"},
        {18, "S"},
        {3, "D"},
        {5, "F"},
        {6, "G"},
        {7, "H"},
        {9, "J"},
        {10, "K"},
        {11, "L"},
        {12, "M"},
        {22, "W"},
        {23, "X"},
        {2, "C"},
        {21, "V"},
        {1, "B"},
        {13, "N"},
        {49, ","},
        {48, ";"},
        {52, ":"},
        {57, "SPACE"},
        {27, "1"},
        {28, "2"},
        {29, "3"},
        {51, "4"},
        {31, "5"},
        {56, "6"},
        {33, "7"},
        {34, "8"},
        {35, "9"},
        {26, "0"},
        {55, "+"},
        {36, "ESC"},
        {-1, NULL},
};

typedef struct {
    sfVector2f fps_m;
    sfVector2f scale;
    sfRectangleShape *rs;
} square;

typedef struct {
    sfText *txt;
    sfFont *f;
} text;

typedef struct {
    sfSprite *sp;
    sfTexture *txtu;
    sfVector2f vect;
    sfIntRect rect;
} dsply;

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct {
    int t;
    int l;
    int max_t;
    int max_l;
    int value;
    int sv_map;
    int ba_save;
    int player;
    int is_speaking;
    dsply **charizard;
    dsply **game;
    dsply **speak;
    text **money;
    dsply **inventory;
    sfVector2f vect;
    sfIntRect rect;
    int *inventorys;
    int **poke_inventory;
    int poke_att;
    int poke_life;
    double damage;
    double damage_2;
    int in_combat;
    int z;
    text **attack;
    char **pok_1;
    char **pok_2;
    int already_att;
    int start;
    int beat_arceus;
    dsply **arceus;
    int arceus_disp;
    float second;
    sfClock *clock;
    sfTime time;
    text **quest;
    dsply **vld_quest;
    int type_you;
    int type_att;
} game;

typedef struct {
    int ph;
    int pos_y;
    int pos_x;
    int s_l;
    int s_r;
    int s_u;
    int s_d;
    int money;
    char **map;
    int key_left;
    int key_right;
    int key_up;
    int key_down;
    int key_left1;
    int key_right1;
    int key_up1;
    int key_down1;
    int key_inventory;
    int key_poked;
    int lock;
    int which;
    int scene;
    sfMusic *msc_cm;
    sfMusic *music;
    sfClock *clock;
    sfTime time;
    float second;
    square **squares;
    text **texts;
    sfRenderWindow *window;
    sfEvent event;
    int music_on_off;
    sfVector2f last;
    int back_menu;
    int done_tuto;
} wdw;

#endif/*STRUCT_H_*/