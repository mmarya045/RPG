/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** destroy
*/

#include "../my_rpg.h"

void my_destroy(sfRenderWindow *window, sfMusic *son)
{
    sfRenderWindow_destroy(window);
    sfMusic_destroy(son);
}
