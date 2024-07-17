/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_event
*/

#include "../my_rpg.h"

void enemie_interaction(rpg_t *rpg)
{
    if (rpg->event.mouseButton.button == sfMouseLeft) {
        sfSprite_setPosition(rpg->enemies->enemies,
        (sfVector2f){-1000, -1000});
        rpg->congrats = sfTrue;
    }
}

void pnj_interaction(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyE) {
            rpg->npc->display_text = sfTrue;
        }
    }
}
