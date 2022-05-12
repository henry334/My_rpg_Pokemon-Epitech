/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** usage.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void usage(void)
{
    my_printf("\nUSAGE\n   ./my_rpg [FLAG]\n");
    my_printf("\nFLAGS\n   -h Print help and exit\n   ");
    my_printf("-n Launch game without music\n");
    my_printf("\nUSER INTERACTIONS IN GAME (KEY THAT CANT BE CHANGE)\n   ");
    my_printf("'E'     Start | Stop interaction with npc\n   "
    "'SPACE' Skip dialogues\n");
    my_printf("   'ESC'   Open pause menu | Exit menu\n");
    my_printf("\nPOKEMON\n   'P'     (by default) Show your pokemon");
    my_printf(" , the first one is your main pokemon\n");
    my_printf("    at 300 xp your pokemon will "
    "upgrade to level 2, win a fight will give you 50xp");
    my_printf("\nINVENTORY\n   'I'     (by default) Show your ");
    my_printf("inventory and your money, you can buy item in the shop, "
    "win a fight will give you 100$\n");
}
