/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** header for the player
*/

#ifndef MYRPG_PLAYER_H_
    #define MYRPG_PLAYER_H_

    #include "my_json.h"
    #include "my_bgs.h"
    #include "rpg_struct.h"

extern const char PLAYER_DATA_PATH[];
extern const char PLAYER_STATS_PATH[];

extern const char PLAYER[];
extern const char PLAYER_STATS[];
extern const char PLAYER_DATA[];

extern const char roulade_key[];

extern const char hurt_key[];

any_t *get_player_stats(window_t *win);

void change_player_pos(player_t *player, float move,
    window_t *win);

bool check_collision(player_t *player, scene_t *scene);

void roulade_event(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void update_player(object_t *obj, scene_t *scene, window_t *win, float dtime);

void update_hurt(player_t *obj, scene_t *scene, window_t *win, float dtime);

int *get_player_spawn(scene_t *scene);

bool check_up_collision(object_t *player, char **map, sfVector2i pos);

void update_roulade(player_t *obj, scene_t *scene, window_t *win, float dtime);

bool check_right_collision(object_t *player, char **map, sfVector2i pos);

bool check_left_collision(object_t *player, char **map, sfVector2i pos);

bool check_down_collision(object_t *player, char **map, sfVector2i pos);

void update_attack(player_t *player, scene_t *scene, window_t *win,
    float dtime);

void set_stop(player_t *player);

void knockback(object_t *obj, scene_t *scene, window_t *win, float time);

bool is_player_on_square(window_t *win, sfFloatRect rect);

void attack_event(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *set_event);

void update_movements(player_t *object, scene_t *scene, window_t *win,
    float delta_time);

void move_on(object_t *object, scene_t *scene, window_t *win,
    set_event_t *event);

void move_off(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

bool check_evolution_stat(player_t *player, float *prev_max_stat,
    const char stat_name[]);

void upgrade_health(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void upgrade_energy(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

int init_player_scale_handling(object_t *obj);

int update_player_view(object_t *obj, window_t *win, float time);

#endif
