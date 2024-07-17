/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** bool_false
*/

#include "../my_rpg.h"

void set_all_bool_false(rpg_t *rpg)
{
    rpg->player->look_down = sfFalse;
    rpg->player->look_up = sfFalse;
    rpg->player->look_left = sfFalse;
    rpg->player->look_right = sfFalse;
}
