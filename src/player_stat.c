/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** player_stat
*/

#include "../my_rpg.h"

void init_player_caracteristics(rpg_t *rpg)
{
    rpg->player_stat->attack_dmg = 10;
    rpg->player_stat->life = 100;
    rpg->player_stat->xp = 0;
}
