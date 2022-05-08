/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** header for the stage launch
*/

#ifndef MYRPG_LAUCNH_STAGE
    #define MYRPG_LAUCNH_STAGE

    #include "my_bgs.h"
    #include "rpg_struct.h"

void next_stage(object_t *obj, scene_t *scene, window_t *win, float time);

int launch_next_stage(window_t *win);

char *get_stage_path(int current_stage);

scene_t *init_scene(const char *stage_path, window_t *win, char *stage_name);

int launch_story_mode(window_t *win, scene_t *scene);

int add_collision_array_in_scene(scene_t *scene);

char *get_stage_name(int stage_id);

int launch_game(bool is_full_screen);

player_t *create_player(window_t *win, scene_t *scene, const char *stats);

char **create_new_map(char **map);

char **stage_map_to_collision_array(scene_t *scene);

int launch_stage(window_t *win, const char *stage_path, int stage_id,
    scene_t *scene);

list_ptr_t *create_pause_menu(scene_t *scene, window_t *win);

int init_hud_elements(window_t *win, scene_t *scene);

int init_dead_menu(window_t *win, scene_t *scene);

int init_stat_upgrade_pop_up(scene_t *scene, list_ptr_t *uid_elements,
    window_t *win);

int init_life_hud(window_t *win, scene_t *scene);

int init_energy_hud(window_t *win, scene_t *scene);

int init_stat_upgrade_pop_up(scene_t *scene, list_ptr_t *uid_elements,
    window_t *win);

int init_hud(window_t *win, scene_t *scene);

int create_inventory(window_t *win);

int init_sounds(scene_t *scene, window_t *win);

int init_movement(player_t *player, window_t *win, scene_t *scene);

int init_xp_hud(window_t *win, scene_t *scene);

void restart_game(scene_t *scene, window_t *win);

#endif
