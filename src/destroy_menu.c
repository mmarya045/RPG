/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** _menu
*/

#include "../my_rpg.h"

void destroy_menu(menu_t *menu)
{
    sfRectangleShape_destroy(menu->button_quit->rect);
    sfRectangleShape_destroy(menu->button_sett->rect);
    sfRectangleShape_destroy(menu->button_start->rect);
    sfText_destroy(menu->title);
}

void destroy_sett(menu_settings_t *menu_sett)
{
    sfRectangleShape_destroy(menu_sett->button_back->rect);
    sfRectangleShape_destroy(menu_sett->button_sound->rect);
    sfText_destroy(menu_sett->text_help);
}
