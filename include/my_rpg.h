/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** header
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <stdbool.h>
    #include <SFML/System/Vector2.h>
    #include "my_bgs_framebuffer.h"

    #define STATS_UPGRADE_KEY "stats_update_pop_up"

    #include "my_bgs.h"
    #include "my_json.h"
    #include "rpg_struct.h"

extern const char HURTED_SOUND[];
extern const char HURT_SOUNG[];
extern const char OPEN_INV_SOUND[];
extern const char CLOSE_INV_SOUND[];
extern const char CONSUM_CAN_SOUND[];
extern const char INFINITY_86_SOUND[];
extern const char PARCHEMIN_SOUND[];
extern const char LEVEL_UP_SOUND[];

extern const char ICON_PATH[];

extern const char DATA_INV_JSON[];
extern const char INV_SCENE[];
extern const char INV_BUTTONS_COMP[];
extern const char KEY_OBJ[];
extern const char POTIONS[];
extern const char INFINITY_86[];
extern const char MAX_LIFE[];
extern const char POTIONS_TEXT[];

extern const char PLAYER_DATA_PATH[];
extern const char PLAYER_STATS_PATH[];

extern const char COLLISION_ARRAY[];

extern const char HUD_ELEMENTS[];
extern const char PAUSE_MENU[];
extern const char DEAD_MESSAGE[];
extern const char DEAD_SCREEN[];

extern const char PLAYER[];
extern const char PLAYER_STATS[];
extern const char PLAYER_DATA[];

extern const char roulade_key[];

extern const char hurt_key[];

extern const char SAVE_PATH[];
extern const char SAVE[];

extern const char STAGE_DATA[];

any_t *get_player_stats(window_t *win);

void change_player_pos(player_t *player, float move,
    window_t *win);

void add_list_obj_to_hud_list(list_ptr_t *hud_elements,
    list_ptr_t *to_cpy, player_t *player);

void click_save(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

bool check_collision(player_t *player, scene_t *scene);

void update_spawner(object_t *obj, scene_t *scene, window_t *win,
    float time);

void roulade_event(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

int move_object_between_scene(window_t *win, scene_t *fst_scene,
    scene_t *scd_scene);

void increment_hud_pos(window_t *win, sfVector2f to_add);

int create_stat_pop_text_from_window(window_t *win, int stat, const char *path,
    sfVector2f pos);

int create_stat_pop_text(scene_t *scene, int stat, const char *path,
    sfVector2f pos);

int create_pop_text(scene_t *scene, const char *path, sfVector2f pos,
    char *text);

void replace_objects(window_t *win, scene_t *scene);

void hud_apply_right_pos(object_t *obj, object_t *player);

int create_map(scene_t *scene);

void update_player(object_t *obj, scene_t *scene, window_t *win, float dtime);

void update_hurt(player_t *obj, scene_t *scene, window_t *win, float dtime);

int *get_player_spawn(scene_t *scene);

bool check_up_collision(object_t *player, char **map, sfVector2i pos);

void update_roulade(player_t *obj, scene_t *scene, window_t *win, float dtime);

bool check_right_collision(object_t *player, char **map, sfVector2i pos);

void square_set_components(object_t *square, dico_t *char_type);

bool check_left_collision(object_t *player, char **map, sfVector2i pos);

bool check_down_collision(object_t *player, char **map, sfVector2i pos);

void update_attack(player_t *player, scene_t *scene, window_t *win,
    float dtime);

void add_main_menu_elements_to_hud_list(window_t *win, scene_t *scene,
    list_ptr_t *hud_list);

void wordarray_free_ptr(void *data);

int init_pause_button(window_t *win, list_ptr_t *pause_menu,
    scene_t *scene, list_ptr_t *hud_elements);

void update_text(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void set_stop(player_t *player);

void knockback(object_t *obj, scene_t *scene, window_t *win, float time);

bool is_player_on_square(window_t *win, sfFloatRect rect);

void attack_event(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *set_event);

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void pressed_button_on(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void pressed_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void exit_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void resume_event_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void settings_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void update_movements(player_t *object, scene_t *scene, window_t *win,
    float delta_time);

void move_on(object_t *object, scene_t *scene, window_t *win,
    set_event_t *event);

void move_off(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void update_dead_message(object_t *object, scene_t *scene,
    window_t *window_t, float delta_time);

void update_dead_screen(object_t *object, scene_t *scene,
    window_t *window_t, float delta_time);

void update_dead(player_t *player, scene_t *screen,
    window_t *win, float delta_time);

void destroy_player(void *player_void);

void dead_event_input(object_t *object, scene_t *scene,
    window_t *window, set_event_t *event);

void set_dead_opacity(object_t *dead_message, object_t *dead_screen);

void free_pop_up(void *list);

int update_hud_stats(object_t *obj, player_t *player, const char stat_name[],
    float stat_value);

int add_hud_to_hud_element(window_t *win, object_t *hud_data,
    player_t *player);

int set_player_default_stats(player_t *player, any_t *stats);

void go_to_home(scene_t *scene, window_t *win);

bool check_evolution_stat(player_t *player, float *prev_max_stat,
    const char stat_name[]);

void upgrade_health(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void upgrade_energy(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void toggle_pop_up(dico_t *dico, const char *key);

void update_xp_bar(object_t *object, scene_t *scene,
    window_t *window, float time);

void level_up(scene_t *scene, window_t *win);

int init_player_scale_handling(object_t *obj);

int update_player_view(object_t *obj, window_t *win, float time);

void set_up_scale(object_t *obj, float time);

void set_down_scale(object_t *obj, float time);

void activate_up_scale(object_t *obj, scene_t *scene,
    window_t *win, float time);

void activate_down_scale(object_t *obj, scene_t *scene,
    window_t *win, float time);

void activate_dash(object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) float time);

void open_inventory(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void close_inventory(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void get_infinity_86(window_t *win);

void get_potions(window_t *win);

void toggle_key_obj(window_t *win);

void heal(window_t *win);

void use_heal_potion(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

int create_number_of_potions(scene_t *scene, window_t *win);

void modif_potion_value(window_t *win, int nbr_potions, bool click);

int check_if_pop_up_true(dico_t *dico, char *key);

int change_xp_bar_stats(any_t *max_xp_data, any_t *actual_xp_data,
    object_t *object, scene_t *scene);

any_t *get_xp_data(player_t *player, const char data_name[]);

void drop_right_item(object_t *obj, window_t *win);

int init_credits(window_t *win);

void go_to_credits(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void go_to_home_direct(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void upgrade_dammage(any_t *player_data);

void update_elder(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void update_intro_magician(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

#endif /* !RPG_H_ */
