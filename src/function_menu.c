/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** function_menu
*/

#include "../my_rpg.h"

void function_menu(sfRenderWindow *window, sfMusic *son)
{
    menu_t *menu = init_menu(window);
    sfEvent event;
    sfTexture *text = sfTexture_createFromFile("assets/fond_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, text, sfFalse);
    sfSprite_setScale(sprite, (sfVector2f){1.362, 1.362});
    sfText_setString(menu->title, "My RPG");
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (evt_menu(window, &event, menu, son) == 1)
            break;
        sfRenderWindow_drawSprite(window, sprite, NULL);
        draw_menu(window, menu);
        sfRenderWindow_display(window);
    }
    destroy_menu(menu);
}

void menu_and_sett(void)
{
    sfRenderWindow *window = create_window(1920, 1080);
    sfMusic *son = sfMusic_createFromFile("assets/alphatron.wav");

    sfMusic_setVolume(son, 50);
    sfMusic_setLoop(son, sfTrue);
    sfMusic_play(son);
    while (sfRenderWindow_isOpen(window)) {
        function_menu(window, son);
        function_settings(window, son);
    }
    my_destroy(window, son);
}
