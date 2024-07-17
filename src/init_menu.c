/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_menu
*/

#include "../my_rpg.h"

void set_title(menu_t *menu)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    menu->title = sfText_create();
    sfText_setFont(menu->title, font);
}

menu_t *init_menu(sfRenderWindow *window)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2u size_win = SIZE_WIN(window);
    sfVector2f pos_quit = {1920 / 2 - 390 / 2, 1080 / 2 + 360};
    sfVector2f size_quit = {390, 99};
    sfTexture *quit_text = sfTexture_createFromFile(EXIT, NULL);
    sfVector2f pos_sett = {1920 / 2 - 390 / 2, (1080 / 2 + 260) - 10};
    sfVector2f size_sett = {390, 99};
    sfTexture *sett_text = sfTexture_createFromFile(OPTION, NULL);
    sfVector2f pos_start = {1920 / 2 - 390 / 2, (1080 / 2 + 160) - 20};
    sfVector2f size_start = {390, 99};
    sfTexture *start_text = sfTexture_createFromFile(PLAY, NULL);

    set_title(menu);
    menu->button_quit = init_button(pos_quit, size_quit, quit_text, NULL);
    menu->button_sett = init_button(pos_sett, size_sett, sett_text, NULL);
    menu->button_start = init_button(pos_start, size_start, start_text, NULL);
    return menu;
}

void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    sfText_setPosition(menu->title, (sfVector2f){100, 300});
    sfText_setCharacterSize(menu->title, 200);
    sfRenderWindow_drawRectangleShape(window, menu->button_quit->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->button_sett->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->button_start->rect, NULL);
    sfRenderWindow_drawText(window, menu->title, NULL);
}
