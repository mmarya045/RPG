/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #include <SFML/Window/Export.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Audio.h>
    #include <fcntl.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <limits.h>

    #define EXIT "./assets/button/exit.png"
    #define OPTION "./assets/button/option.png"
    #define PLAY "./assets/button/play.png"
    #define BACK "./assets/button/cancel.png"
    #define SOUND_BUTTON "./assets/button/son.png"
    #define CURSOR "./assets/button/cursor.png"
    #define MUTE "./assets/button/mute.png"
    #define SIZE_WIN(win) sfRenderWindow_getSize(win)
    #define PLAYER_HT sfSprite_getGlobalBounds(rpg)

typedef struct enemies_s {
    int life;
    sfSprite *enemies;
    sfIntRect orc_rect;
    int x;
    int y;
} enemies_t;

typedef struct player_s {
    sfBool close_enemie;
    int last_direction;
    sfSprite *player_sp;
    sfSprite *player_attack_sp;
    sfIntRect rect_basic;
    sfIntRect rect_attack;
    sfBool look_up;
    sfBool look_down;
    sfBool look_left;
    sfBool look_right;
    sfBool is_attacking;
    sfVector2f player_pos;
    sfRectangleShape *player_hitbox;
} player_t;

typedef struct player_stats_s {
    int xp;
    int attack_dmg;
    int life;
} stat_t;

typedef struct npc_s {
    sfSprite *dialog;
    sfBool display_text;
    sfSprite *npc_idle;
    sfSprite *npc_jump;
    sfIntRect npc_idle_rect;
    sfIntRect npc_jump_rect;
    sfRectangleShape *npc_hitbox;
    sfBool collis;
} npc_t;

typedef struct rpg_s {
    sfBool congrats;
    sfBool menu_on;
    sfView *view;
    player_t *player;
    enemies_t *enemies;
    stat_t *player_stat;
    npc_t *npc;
    sfClock *clock;
    sfEvent event;
    sfRenderWindow *window;
    sfTime time;
    float seconds;
    sfSprite *background;
    sfImage *masque;
    int speed;
    sfSprite *structure;
} rpg_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
} button_t;

typedef struct cursor_s {
    sfCircleShape *button_cursor;
} cursor_t;

typedef struct menu_s {
    button_t *button_quit;
    button_t *button_sett;
    button_t *button_start;
    sfText *title;
} menu_t;

typedef struct menu_settings_s {
    button_t *button_back;
    button_t *button_sound;
    sfBool sound;
    sfText *text_help;
} menu_settings_t;
typedef menu_settings_t menu_set_t;
typedef sfRenderWindow Window_t;
typedef sfVector2f Vector_t;
typedef button_t but_t;

sfRenderWindow *create_window(unsigned int width, unsigned int height);
int evt_menu(sfRenderWindow *, sfEvent *, menu_t *, sfMusic *);
button_t *init_button(Vector_t pos, Vector_t sze, sfTexture *, but_t *);
sfBool is_clicked(button_t *button, sfMouseButtonEvent *event);
void my_destroy(sfRenderWindow *window, sfMusic *son);
sfIntRect init_rect(sfIntRect rect, int width, int height);
menu_t *init_menu(sfRenderWindow *window);
void draw_menu(sfRenderWindow *window, menu_t *menu);
int menu_event(menu_t *, sfEvent *, sfRenderWindow *, sfMusic *);
void function_settings(sfRenderWindow *window, sfMusic *son);
void function_menu(sfRenderWindow *window, sfMusic *son);
void destroy_menu(menu_t *menu);
void menu_and_sett(void);
int set_menu_event(menu_set_t *, sfEvent *, sfMusic *);
menu_settings_t *init_sett(void);
int evt_sett(sfRenderWindow *, sfEvent *, menu_settings_t *, sfMusic *);
void draw_settings(sfRenderWindow *window, menu_settings_t *menu_sett);
void destroy_sett(menu_settings_t *menu_sett);
void manage_sound(sfBool sound, sfMusic *son);
int my_getnbr(const char *str);
int my_strcmp(const char *s1, const char *s2);
cursor_t *init_cursor(sfVector2f origin, sfVector2f pos, sfTexture *texture);
sfBool is_hover(button_t *button, sfMouseMoveEvent *event);
int play(void);
sfSprite *sprite_create(char *file);
sfSprite *background_create(char *file);
void move_rect(sfIntRect *rect, int offset, int max_value);
void close_window(sfRenderWindow *window);
void handle_close_window(sfEvent event, sfRenderWindow *window);
void set_all_bool_false(rpg_t *rpg);
void stop_last_direction(rpg_t *rpg, sfIntRect *rect);
void malloc_rpg_elem(rpg_t *rpg);
void init_player_sprite(rpg_t *rpg);
void init_sfview(rpg_t *rpg);
void init_window_elem(rpg_t *rpg);
void init_player_caracteristics(rpg_t *rpg);
rpg_t *init_struct(void);
void handle_z_key(rpg_t *rpg);
void handle_q_key(rpg_t *rpg);
void handle_s_key(rpg_t *rpg);
void handle_d_key(rpg_t *rpg);
void basic_movement(rpg_t *rpg);
void attack_up(rpg_t *rpg);
void attack_down(rpg_t *rpg);
void attack_right(rpg_t *rpg);
void attack_left(rpg_t *rpg);
void handle_attack(rpg_t *rpg);
void handle_in_game_inv(rpg_t *rpg);
void handle_event(rpg_t *rpg);
void handle_window(rpg_t *rpg);
void handle_sprite_permutation(rpg_t *rpg);
void rect_animation_clock(rpg_t *rpg);
void change_button_sound(button_t *button);
sfRenderWindow *resolution(sfRenderWindow *win, sfEvent event);
sfImage *map_masque_create(char *file);
sfBool colision(rpg_t *rpg, int direction);
void display_text_pnj(rpg_t *rpg, char *content);
void init_enemie_sprite(rpg_t *rpg);
void set_texture_rect(rpg_t *rpg);
void pnj_interaction(rpg_t *rpg);
void enemie_interaction(rpg_t *rpg);
void handle_collision_enemie(sfFloatRect player_hitbox,
    sfFloatRect enemie_hitbox, rpg_t *rpg);
void handle_collision_pnj(sfFloatRect player_hitbox,
    sfFloatRect npc_hitbox, rpg_t *rpg);
void display_text_pnj(rpg_t *rpg, char *content);
void display_text_dialog(rpg_t *rpg);

#endif /* !MY_RPG_H_ */
