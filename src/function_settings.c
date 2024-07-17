/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** function_settings
*/

#include "../my_rpg.h"

void function_settings(sfRenderWindow *window, sfMusic *son)
{
    menu_settings_t *menu_sett = init_sett();
    sfEvent event;
    const char *str = "Changer resolution: P\nTouche: ZQSD";

    sfText_setString(menu_sett->text_help, str);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (evt_sett(window, &event, menu_sett, son) == 1)
            break;
        draw_settings(window, menu_sett);
        sfRenderWindow_display(window);
    }
    destroy_sett(menu_sett);
}
