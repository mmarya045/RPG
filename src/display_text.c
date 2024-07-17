/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_window
*/

#include "../my_rpg.h"

void display_text_pnj(rpg_t *rpg, char *content)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/pnj_dialog.ttf");
    sfVector2f pos = sfSprite_getPosition(rpg->npc->npc_idle);

    pos.x -= 70;
    pos.y -= 60;
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 30);
    sfText_setString(text, content);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void display_text_dialog(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/pnj_dialog.ttf");
    sfVector2f pos = sfSprite_getPosition(rpg->npc->dialog);

    pos.x += 30;
    pos.y += 250;
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 30);
    sfText_setString(text, "Bonjour, tue l'ennemi pour \nreussir la quete !");
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}
