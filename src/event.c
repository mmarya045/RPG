/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** event
*/

#include "../my_rpg.h"

int menu_event(menu_t *menu, sfEvent *event, sfRenderWindow *win, sfMusic *son)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (is_clicked(menu->button_quit, &event->mouseButton)) {
            sfRenderWindow_close(win);
            sfRenderWindow_destroy(win);
            sfMusic_destroy(son);
            exit(0);
        }
        if (is_clicked(menu->button_sett, &event->mouseButton)) {
            return 1;
        }
        if (is_clicked(menu->button_start, &event->mouseButton)) {
            sfRenderWindow_close(win);
        }
    }
    return 0;
}

int set_menu_event(menu_set_t *menu_setting, sfEvent *event, sfMusic *son)
{
    FILE *fd;
    char *volume = NULL;
    size_t n = 0;
    float vol = 0;

    if (event->type == sfEvtMouseButtonPressed) {
        if (is_clicked(menu_setting->button_back, &event->mouseButton))
            return 1;
        if (is_clicked(menu_setting->button_sound, &event->mouseButton)) {
            change_button_sound(menu_setting->button_sound);
            menu_setting->sound = !menu_setting->sound;
        }
    }
    return 0;
}

int evt_menu(sfRenderWindow *win, sfEvent *event, menu_t *menu, sfMusic *son)
{
    sfRenderWindow_setFramerateLimit(win, 144);
    while (sfRenderWindow_pollEvent(win, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(win);
            sfRenderWindow_destroy(win);
            sfMusic_destroy(son);
            exit(0);
        }
        if (event->type == sfEvtMouseMoved) {
            is_hover(menu->button_quit, &event->mouseMove);
            is_hover(menu->button_sett, &event->mouseMove);
            is_hover(menu->button_start, &event->mouseMove);
        }
        if (menu_event(menu, event, win, son) == 1)
            return 1;
    }
    return 0;
}

int evt_sett(Window_t *win, sfEvent *evt, menu_set_t *menu_sett, sfMusic *son)
{
    sfRenderWindow_setFramerateLimit(win, 144);
    while (sfRenderWindow_pollEvent(win, evt)) {
        if (evt->type == sfEvtClosed) {
            sfRenderWindow_close(win);
            sfRenderWindow_destroy(win);
            sfMusic_destroy(son);
            exit(0);
        }
        if (evt->type == sfEvtMouseMoved) {
            is_hover(menu_sett->button_back, &evt->mouseMove);
            is_hover(menu_sett->button_sound, &evt->mouseMove);
        }
        if (set_menu_event(menu_sett, evt, son) == 1)
            return 1;
        manage_sound(menu_sett->sound, son);
    }
    return 0;
}
