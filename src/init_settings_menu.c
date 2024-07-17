/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_settings_menu
*/

#include "../my_rpg.h"

menu_settings_t *init_sett(void)
{
    menu_settings_t *menu_sett = malloc(sizeof(menu_settings_t));
    sfVector2f pos_back = {20, 956};
    sfVector2f size_back = {283.5, 93};
    sfTexture *back_text = sfTexture_createFromFile(BACK, NULL);
    sfVector2f pos_snd = {1715, 888};
    sfVector2f size_snd = {159, 163.5};
    sfTexture *sound_text = sfTexture_createFromFile(SOUND_BUTTON, NULL);
    sfTexture *cursor_texture = sfTexture_createFromFile(CURSOR, NULL);
    sfVector2f size_bar_cur = {200, 10};
    sfVector2f pos_bar_cur = {300, 300};
    sfVector2f ori_curs = {-390, -295};
    sfVector2f pos_curs = {390, 295};
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    menu_sett->text_help = sfText_create();
    sfText_setFont(menu_sett->text_help, font);
    menu_sett->sound = sfTrue;
    menu_sett->button_back = init_button(pos_back, size_back, back_text, NULL);
    menu_sett->button_sound = init_button(pos_snd, size_snd, sound_text, NULL);
    return menu_sett;
}

void draw_settings(sfRenderWindow *win, menu_settings_t *menu_sett)
{
    sfRectangleShape *rect_back = menu_sett->button_back->rect;
    sfRectangleShape *rect_sound = menu_sett->button_sound->rect;

    sfText_setPosition(menu_sett->text_help, (sfVector2f){40, 540});
    sfRenderWindow_drawText(win, menu_sett->text_help, NULL);
    sfRenderWindow_drawRectangleShape(win, rect_back, NULL);
    sfRenderWindow_drawRectangleShape(win, rect_sound, NULL);
}
