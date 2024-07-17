/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** malloc_rpg_elem
*/

#include "../my_rpg.h"

void malloc_rpg_elem(rpg_t *rpg)
{
    rpg->player = malloc(sizeof(player_t));
    rpg->npc = malloc(sizeof(npc_t));
    rpg->enemies = malloc(sizeof(enemies_t));
    rpg->speed = 10;
}
