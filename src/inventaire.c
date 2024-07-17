/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** inventaire
*/

#include "../my_rpg.h"

void handle_in_game_inv(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyA) {
        if (rpg->menu_on == sfTrue) {
            rpg->menu_on = sfFalse;
            return;
        } else
            rpg->menu_on = sfTrue;
    }
}
