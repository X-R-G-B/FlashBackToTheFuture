/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** my bgs components
*/

#ifndef BGS_COMPONENTS_
    #define BGS_COMPONENTS_

    #include "my_bgs.h"

static const char ON_HOVER_KEY[] = "__on_hover";
static const char ON_RIGHT_KEY[] = "__on_right_click";
static const char ON_LEFT_KEY[] = "__on_left_click";
static const char ON_COLLISION[] = "__on_collision";
static const char SET_EVENT[] = "__set_event";
static const char COMP_CHRONO[] = "__sprite_chrono";
static const char COMP_HEALTH[] = "__sprite_health";
static const char COMP_MOVE[] = "__sprite_move";
static const char COMP_ANIM[] = "__sprite_anim";

typedef struct sprite_anim_s sprite_anim_t;
typedef struct sprite_move_s sprite_move_t;
typedef struct sprite_health_s sprite_health_t;
typedef struct on_collision_s on_collision_t;
typedef struct sprite_chrono_s sprite_chrono_t;
typedef struct on_left_click_s on_left_click_t;
typedef struct on_right_click_s on_right_click_t;
typedef struct on_hover_s on_hover_t;
typedef struct set_event_s set_event_t;
typedef struct event_node_s event_node_t;
typedef struct node_params_s node_params_t;

enum event_type {
    MOUSE,
    KEY
};

struct node_params_s {
    sfMouseButton mouse;
    sfKeyCode key;
    enum event_type event;
};

struct event_node_s {
    union event_code {
        sfMouseButton mouse;
        sfKeyCode key;
    } event_code;
    enum event_type event_type;
};

struct set_event_s {
    list_ptr_t *list_event;
    event_node_t input_key;
    bool hover;
    bool prev_call;
    void (*on)(object_t *object, scene_t *scene, window_t *win,
        set_event_t *event);
    void (*off)(object_t *object, scene_t *scene, window_t *win,
        set_event_t *event);
};

struct sprite_anim_s {
    sfIntRect rect;
};

struct sprite_move_s {
    sfVector2f vect;
};

struct sprite_health_s {
    float life;
    float max_life;
    void (*dead)(object_t *object, scene_t *scene, window_t *win);
    bool is_alive;
};

struct on_collision_s {
    char key[255];
    dico_t *collisions_dico;
    void (*collision)(object_t *this, object_t *other, scene_t *scene,
        window_t *win);
};

struct sprite_chrono_s {
    float seconds;
    float refresh_rate;
};

struct on_hover_s {
    void (*hover)(object_t *, scene_t *, window_t *win);
};

struct on_right_click_s {
    bool prev_right_click;
    void (*right_click)(object_t *, scene_t *, window_t *win);
};

struct on_left_click_s {
    bool prev_left_click;
    void (*left_click)(object_t *, scene_t *, window_t *win);
};

/**
** @brief add a component to the window component
**
** You can add any component to a window component
**
** @param win window_t window in which you will add a component
** @param data void *data is your component
** @param key const char[] is your key linked to the component
** @param destroy void (*destroy)(void *) is the function pointer
** which will destroy your component
**
** @return {
** BGS_ERR_INPUT : win or data or key is NULL
** BGS_ERR_MALLOC : malloc failed
** BGS_OK : the component has been successfully added to the window
** }
**/
int window_add_component(window_t *win, void *data, const char key[],
    void (*destroy)(void *));

int object_add_components(object_t *object, void *data, const char key[],
    void (*destroy)(void *));

int object_add_hover_event(object_t *object, void (*hover)(object_t *, dico_t *,
    window_t *win));

int object_add_right_click_event(object_t *object,
    void (*right_click)(object_t *, dico_t *, window_t *win));

int object_add_left_click_event(object_t *object, void (*left_click)(object_t *,
    dico_t *, window_t *win));

int object_add_chrono(object_t *object, float seconds,
    float refresh_rate);

int object_add_sprite_text_solid(object_t *object);

int object_add_sprite_health(object_t *object, float life, float max_life,
    void (*dead)(object_t *object, scene_t *scene, window_t *win));

int object_add_sprite_move(object_t *object, sfVector2f vect);

int object_add_sprite_anim(object_t *object, sfIntRect rect);

void object_update_mouse_event(object_t *object, scene_t *scene,
    window_t *win);

int object_add_collision(object_t *object, scene_t *scene,
    void (*collision)(object_t *this, object_t *other, scene_t *scene,
    window_t *win));

/**
** @brief set object as visible
**
** @param object object to set
**/
void set_display(object_t *object);

/**
** @brief set object as not visible
**
** @param object object to set
**/
void unset_display(object_t *object);

int object_set_event(object_t *object, set_event_t *usr_event);

/**
** @brief add a conditon event to an already created event
**
** choose between sfMouseButton and sfKeyCode with the enum and this as an
** added condition to trigger the event
**
** @param event event in which the condition will be added
** @param params {sfMouseButton, sfKeyCode, enum event_type} condition to add
**
** @return
**/
int event_add_node(set_event_t *event, node_params_t params);

/**
** @brief create an event for an object
**
** @param on function to call when event trigger
** @param hover whether the event need to have the cursor on the object
** @param object object in which the event will be added
** @param off function called when the event stops
**
** @return {
** NULL : object is NULL,
** NULL : malloc failed,
** set_event_t *: the event has been created
** }
**/
set_event_t *create_event(void (*on)(object_t *, scene_t *, window_t *,
    set_event_t *), bool hover, object_t *object,
    void (*off)(object_t *, scene_t *, window_t *, set_event_t *));

void object_check_health(object_t *object, scene_t *scene,
    window_t *win);

void check_event(set_event_t *set_event, object_t *object,
    window_t *win, scene_t *scene_components);

#endif /* !BGS_COMPONENTS_ */
