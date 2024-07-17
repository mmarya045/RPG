/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_window
*/

#include "../my_rpg.h"

void display_congrats_text(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/pnj_dialog.ttf");
    sfVector2f pos = sfSprite_getPosition(rpg->player->player_sp);

    pos.x += 400;
    pos.y -= 500;
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 40);
    sfText_setString(text, "QUETE REUSSIE !");
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

sfRectangleShape *create_hitbox(sfSprite *sprite)
{
    sfFloatRect player_fr;
    sfRectangleShape *player_hitbox;

    player_fr = sfSprite_getGlobalBounds(sprite);
    player_hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(player_hitbox, sfSprite_getPosition(sprite));
    sfRectangleShape_setSize(player_hitbox,
    (sfVector2f){player_fr.width, player_fr.height});
    sfRectangleShape_setFillColor(player_hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(player_hitbox, sfWhite);
    sfRectangleShape_setOutlineThickness(player_hitbox, 1.0f);
    return player_hitbox;
}

void handle_dialog(rpg_t *rpg)
{
    sfVector2f pos;

    pos = sfSprite_getPosition(rpg->player->player_sp);
    pos.x -= 250;
    pos.y += 135;
    sfSprite_setPosition(rpg->npc->dialog, pos);
}

void draw_window_elem(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->background, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->npc->npc_idle, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->player->player_sp, NULL);
    if (rpg->npc->collis == sfTrue)
        display_text_pnj(rpg, "   PRESS E\n  to interact\n");
    sfRenderWindow_drawSprite(rpg->window, rpg->structure, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->enemies->enemies, NULL);
    if (rpg->npc->display_text == sfTrue) {
        handle_dialog(rpg);
        sfRenderWindow_drawSprite(rpg->window, rpg->npc->dialog, NULL);
        display_text_dialog(rpg);
    }
}

void handle_window(rpg_t *rpg)
{
    sfRenderWindow_setView(rpg->window, rpg->view);
    rpg->player->player_hitbox = create_hitbox(rpg->player->player_sp);
    rpg->npc->npc_hitbox = create_hitbox(rpg->npc->npc_idle);
    sfRenderWindow_clear(rpg->window, sfBlack);
    draw_window_elem(rpg);
    if (rpg->congrats == sfTrue) {
        display_congrats_text(rpg);
    }
    sfRenderWindow_drawSprite(rpg->window,
    rpg->player->player_attack_sp, NULL);
    sfRenderWindow_display(rpg->window);
}
