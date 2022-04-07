/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** header
*/

#ifndef RPG_H_
    #define RPG_H_

    #define RET_OK 0
    #define RET_ERR_MALLOC 1
    #define RET_ERR_INPUT 2

    #include "my_bgs.h"

static const char PLAYER_DATA[] = "./assets/data/player/data.json";
static const char PLAYER_STATS[] = "./assets/data/player/stats.json";

static const char STORY_DATA_PATH[] =
    "./assets/data/story_mode/save.json";
static const char SAVE[] = "story_mode_data";

typedef enum state_e {
    ATTACKING,
    MOVING,
    STOP,
    DYING,
    DIE,
    STUNT
} state_t;

typedef enum dir_e {
    UP,
    LEFT,
    DOWN,
    RIGHT
} dir_t;

typedef struct player_s {
    state_t state;
    dir_t dir;
    object_t *obj;
} player_t;

void click_save(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event);

void update_player(object_t *obj, scene_t *scene, window_t *win, float dtime);

void update_attack(player_t *player, scene_t *scene, window_t *win,
    float dtime);

int launch_story_mode(window_t *win, const char save_path[]);

int launch_game(void);

void set_stop(player_t *player);

player_t *create_player(window_t *win, scene_t *scene, const char *stats);

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

#endif /* !RPG_H_ */
