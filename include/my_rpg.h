/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** header
*/

#ifndef RPG_H_
    #define RPG_H_

    #define RET_OK 0
    #define RET_ERR_MALLOC 1
    #define RET_ERR_INPUT 2

    #define SQUARE_SIZE 40

    #define WIN_SIZE_Y 1080
    #define WIN_SIZE_X 1920

    #include <SFML/System/Vector2.h>
    #include "my_bgs.h"

static const char PLAYER_DATA[] = "./assets/data/player/data.json";
static const char PLAYER_STATS[] = "./assets/data/player/stats.json";

static const char COLLISION_ARRAY[] = "collision array";

static const char UID_ELEMENTS[] = "uid_elements";

static const char STORY_DATA_PATH[] =
    "./assets/data/story_mode/save.json";
static const char SAVE[] = "story_mode_data";

static const char STAGE_DATA[] = "stage_data";

typedef enum state_e {
    ATTACKING,
    MOVING,
    DYING,
    STOP,
    DIE,
    STUNT
} state_t;

typedef enum dir_e {
    UNKNOWN_STATE = -1,
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
} dir_t;

typedef struct player_s {
    state_t state;
    dir_t dir;
    object_t *obj;
    sfView *view;
} player_t;

void add_list_obj_to_uid_list(list_ptr_t *uid_elements,
    list_ptr_t *to_cpy, player_t *player);

char *get_stage_path(int current_stage);

void click_save(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

bool check_collision(player_t *player, scene_t *scene);

int move_object_between_scene(window_t *win, char *fst_scene_key,
    char *scd_scene_key);

void increment_uid_pos(scene_t *scene, sfVector2f to_add);

void uid_apply_right_pos(object_t *obj, object_t *player);

int create_map(scene_t *scene);

void update_player(object_t *obj, scene_t *scene, window_t *win, float dtime);

bool check_up_collision(object_t *player, char **map, sfVector2i pos);

bool check_right_collision(object_t *player, char **map, sfVector2i pos);

bool check_left_collision(object_t *player, char **map, sfVector2i pos);

bool check_down_collision(object_t *player, char **map, sfVector2i pos);

void update_attack(player_t *player, scene_t *scene, window_t *win,
    float dtime);

void add_main_menu_elements_to_uid_list(window_t *win, scene_t *scene,
    list_ptr_t *uid_list);

int launch_story_mode(window_t *win, const char save_path[]);

int add_collision_array_in_scene(scene_t *scene);

void wordarray_free_ptr(void *data);

char *get_stage_name(int stage_id);

int launch_game(void);

void set_stop(player_t *player);

void knockback(object_t *obj, scene_t *scene, window_t *win, float time);

bool is_player_on_square(window_t *win, object_t *square);

player_t *create_player(window_t *win, scene_t *scene, const char *stats);

char **create_new_map(char **map);

char **stage_map_to_collision_array(scene_t *scene);

int launch_stage(window_t *win, char *stage_path, int stage_id);

void attack_event(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *set_event);

list_ptr_t *create_pause_menu(scene_t *scene);

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

int init_dead_menu(window_t *win, scene_t *scene);

void destroy_player(void *player_void);

#endif /* !RPG_H_ */
