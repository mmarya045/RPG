/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** last_direction
*/

#include "../my_rpg.h"

void stop_last_direction(rpg_t *rpg, sfIntRect *rect)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        set_all_bool_false(rpg);
        if (rpg->event.key.code == sfKeyZ) {
            (*rect) = (sfIntRect){0, 96, 48, 48};
            rpg->player->look_up = sfTrue;
        }
        if (rpg->event.key.code == sfKeyQ) {
            (*rect) = (sfIntRect){0, 336, 48, 48};
            rpg->player->look_left = sfTrue;
        }
        if (rpg->event.key.code == sfKeyS) {
            (*rect) = (sfIntRect){0, 0, 48, 48};
            rpg->player->look_down = sfTrue;
        }
        if (rpg->event.key.code == sfKeyD) {
            (*rect) = (sfIntRect){0, 48, 48, 48};
            rpg->player->look_right = sfTrue;
        }
    }
}
