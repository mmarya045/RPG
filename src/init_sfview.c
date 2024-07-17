/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_sfview
*/

#include "../my_rpg.h"

void init_sfview(rpg_t *rpg)
{
    rpg->view = sfView_create();
    sfView_setSize(rpg->view, (sfVector2f){1670, 1080});
}
