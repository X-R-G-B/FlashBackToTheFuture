/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** npc header file
*/

#ifndef NPC_RPG_H_
    #define NPC_RPG_H_

    #include <stdbool.h>
    #include "rpg_struct.h"
    #include "list.h"
    #include "my_bgs.h"
    #include "my_json.h"

typedef struct dialog_manager_s dialog_manager_t;
typedef struct text_dialog_s text_dialog_t;
typedef struct npc_data_func_s npc_data_func_t;

struct dialog_manager_s {
    list_ptr_t *dialogues;
    char *text;
};

struct text_dialog_s {
    char *str;
    bool need_pause;
    void (*callback)(const char *str, scene_t *scene,
        window_t *win, void *data);
    float time;
    void *data;
};

struct npc_data_func_s {
    void (*callback)(object_t *npc, scene_t *scene, window_t *win);
};

extern const char compo_dialog[];

extern const char npc_json[];

extern const char npc_data_callback[];

extern const char json_magician[];

extern const sfVector2f pos_dialog;
extern const sfVector2f pos_text;

void init_chest(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void callback_npc(__attribute__((unused)) object_t *npc,
    scene_t *scene,
    __attribute__((unused)) window_t *win);

int destroy_text_dialog(void *dialog_void, scene_t *scene, window_t *win,
    bool force_quit);

int add_event_continue_to_dialog(object_t *dialog);

int add_event_quit_to_dialog(object_t *dialog);

int init_dialog(scene_t *scene, window_t *win);

object_t *add_npc(scene_t *scene, const char *path, sfVector2f pos,
    void (*callback)(object_t *npc, scene_t *scene, window_t *win), const char *path_root);

void update_npc(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void update_text_dialog(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void update_dialog(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void update_grandpa(object_t *obj, scene_t *scene, window_t *win, float dtime);

int aplly_rect_npc(any_t *jsonrect, any_t *current, object_t *npc);

text_dialog_t *add_text_dialog(window_t *win, const char *text,
    bool need_pause, void (*callback)(const char *str,
    scene_t *scene, window_t *win, void *data));

void call_callback_npc(object_t *npc, scene_t *scene, window_t *win);

int add_text_dialog_json(window_t *win, const char *path,
    void (*callback)(const char *str, scene_t *scene, window_t *win,
        void *data), void *data);

char *parseprety(const char *str);

void check_have_enough_infinity_86(player_t *player, object_t *chest,
    window_t *win, scene_t *scene);

char *parseprety_free(char *str);

void reaload_dialogs(const char *str, scene_t *scene, window_t *win,
    void *data);

void create_view_rotation(scene_t *scene, const char *path_root);

void update_magician(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime);

void init_npc_spawner(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float time);

void event_quit_dialog_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void skip_event_magician_tp(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void update_end_magician(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

#endif
