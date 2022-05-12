/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** create_tuto.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply **send_creat_tuto(void)
{
    dsply **save = malloc(sizeof(*save) * 5);
    save[0] = create_object("./ressources/tutoriel/back.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    save[1] = create_object("./ressources/tutoriel/Prof.png",
    (sfVector2f){450, 285}, (sfIntRect){0, 0, 141, 250});
    save[2] = create_object("./ressources/tutoriel/ectoplasma.png",
    (sfVector2f){375, 450}, (sfIntRect){0, 0, 84, 78});
    save[3] = create_object("./ressources/dialogue/dialogue_box.png",
    (sfVector2f){90, 535}, (sfIntRect){0, 0, 900, 180});
    save[4] = NULL;
    return save;
}

text **follow_tuto(text **save)
{
    save[8] = create_text("and create a very strong bond with them."
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[9] = create_text("Me? I'm happy to do\n"
    "Pokemon research.", (sfVector2f){150, 550}, 65, sfBlack);
    save[10] = create_text("Alright, how are you feeling?"
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[11] = create_text("You are about to embark for\n"
    "a once-in-a-lifetime adventure", (sfVector2f){150, 550}, 65, sfBlack);
    save[12] = create_text("whose goal will be to capture Arceus\nor"
    " to beat him for good.", (sfVector2f){150, 550}, 65, sfBlack);
    save[13] = create_text("Before diving into the world of Pokemon\n"
    "you will have to choose your Pokemon",
    (sfVector2f){136, 550}, 65, sfBlack);
    save[14] = NULL;
    return save;
}

text **send_text_tuto(void)
{
    text **save = malloc(sizeof(save) * 15);
    save[0] = create_text("Hello!\nWhat a joy to meet you!"
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[1] = create_text("Welcome to the world of Pokemon!"
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[2] = create_text("My name is Chen."
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[3] = create_text("But everyone calls me\nsimply the\
    Professor Pokemon.", (sfVector2f){150, 550}, 65, sfBlack);
    save[4] = create_text("This world is populated by creatures\n"
    "called Pokemon!", (sfVector2f){150, 550}, 65, sfBlack);
    save[5] = create_text("We humans live with\nPokemon."
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[6] = create_text("We happen to play\nor work together."
    , (sfVector2f){150, 550}, 65, sfBlack);
    save[7] = create_text("Some people use the\nPokemon\
    to fight", (sfVector2f){150, 550}, 65, sfBlack);
    save = follow_tuto(save);
    return save;
}