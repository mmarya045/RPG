/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_event
*/

#include "../my_rpg.h"

void handle_collision_pnj(sfFloatRect player_hitbox,
    sfFloatRect npc_hitbox, rpg_t *rpg)
{
    if (sfFloatRect_intersects(&player_hitbox,
            &npc_hitbox, NULL) == sfTrue) {
            rpg->npc->collis = sfTrue;
            pnj_interaction(rpg);
        } else {
            rpg->npc->collis = sfFalse;
            rpg->npc->display_text = sfFalse;
    }
}

void handle_collision_enemie(sfFloatRect player_hitbox,
    sfFloatRect enemie_hitbox, rpg_t *rpg)
{
    if (sfFloatRect_intersects(&player_hitbox,
            &enemie_hitbox, NULL) == sfTrue) {
            rpg->player->close_enemie = sfTrue;
            enemie_interaction(rpg);
        } else {
            rpg->player->close_enemie = sfFalse;
    }
}
