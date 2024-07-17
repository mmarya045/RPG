/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_struct
*/

#include "../my_rpg.h"

rpg_t *init_struct(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    rpg->congrats = sfFalse;
    malloc_rpg_elem(rpg);
    init_window_elem(rpg);
    rpg->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    return rpg;
}
