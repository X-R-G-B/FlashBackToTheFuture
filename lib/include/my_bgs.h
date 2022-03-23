/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** bgs
*/

#ifndef BGS_H_
    #define BGS_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include "list.h"
    #include "my_dico.h"

    #define BGS_OK 0
    #define BGS_ERR_PATH 1
    #define BGS_ERR_MALLOC 2
    #define BGS_ERR_INPUT 3

static const char SET_ICON[] = "__set_icon";

typedef struct time_clock_s time_clock_t;
typedef struct object_s object_t;
typedef struct window_s window_t;
typedef struct scene_s scene_t;
typedef struct sprite_bigdata_s sprite_bigdata_t;
typedef struct text_bigdata_s text_bigdata_t;

enum object_type {
    SPRITE,
    TEXT,
    AUDIO,
    CUSTOM,
    UNSET
};

struct sprite_bigdata_s {
    sfImage *image;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
};

struct text_bigdata_s {
    sfFont *font;
    sfVector2f pos;
};

struct object_s {
    enum object_type type;
    union bigdata {
        sprite_bigdata_t sprite_bigdata;
        text_bigdata_t text_bigdata;
    } bigdata;
    union drawable {
        sfSprite *sprite;
        sfText *text;
        sfMusic *music;
    } drawable;
    dico_t *components;
    bool is_visible;
    void (*update)(object_t *, scene_t *scene, window_t *win, float);
    void (*display)(object_t *, dico_t *scene_components,
        dico_t *win_components, sfRenderWindow *win);
};

struct time_clock_s {
    float seconds;
    float refresh_time;
    sfClock *clock;
    sfTime time;
};

struct scene_s {
    bool pause;
    sfColor bg_color;
    list_ptr_t *to_remove;
    list_ptr_t *updates;
    list_ptr_t *objects;
    list_ptr_t *displayables;
    dico_t *components;
    void (*destroy)(void *);
};

struct window_s {
    bool click_prev_call;
    sfRenderWindow *win;
    int scene_index;
    list_ptr_t *scenes;
    dico_t *components;
};

int window_set_icon(window_t *win, char const path[]);

// ----------------------------------------------------------------------------
// add.c
// ----------------------------------------------------------------------------

/**
** @brief add a scene_t to a window_t
** @param win the window in which the scene will be added
** @param scene the scene to add
** @return BGS_ERR_INPUT : win or scene is NULL;
** BGS_ERR_MALLOC : malloc failed;
** BGS_OK : the scene has been added;
**/
int window_add_scene(window_t *win, scene_t *scene);

/**
** @brief add an object_t to a scene_t
** @param scene the scene in which the object will be added
** @param object the object to add
** @return BGS_ERR_INPUT : scene or object is NULL
** @return BGS_ERR_MALLOC : malloc failed
** @return BGS_OK : the object has been added
**/
int scene_add_object(scene_t *scene, object_t *object);

// ----------------------------------------------------------------------------
// create_object.c
// ----------------------------------------------------------------------------

/**
** @brief modify an object to be a music
** @param object the object to modify
** @param path path to the music (.ogg is better)
** @param play_now if the music need to play directly
** @param is_loop if the music need to be a music loop directly
** @return BGS_ERR_INPUT : object or path is NULL
** @return BGS_ERR_PATH : the given path is bad
** @return BGS_OK : the object is set to be audio
**/
int object_set_audio(object_t *object, char const *path, bool play_now,
    bool loop_now);

/**
** @brief add a custom type of data to object components
** Accessible via TODO
** CAUTION: if the create() function segv, the entire program will segv
** @param object the object in which the custom will be added
** @param create a function to create the custome data
** @param destroy a function to destroy/free the custom type
** @param key the key to access the custom data
** @return BGS_ERR_INPUT : object or create of key is NULL
** @return BGS_OK : the custom data is added ot the object
**/
int object_set_custom(object_t *object);

/**
** @brief modify an object to be a text
** @param object the object to modify
** @param path the font to use
** @param text the text to draw
** @param scene the scene to which the object will be added
** @return BGS_ERR_INPUT : object or path or text or scene is NULL
** @return BGS_ERR_PATH : the given path is bad
** @return BGS_ERR_MALLOC : malloc failed
** @return BGS_OK : the object is set to text and scene is update
**/
int object_set_text(object_t *object, char const *path, char const *text,
    sfVector2f pos);

/**
** @brief modify an object to be a sprite
** @param object the object to modify
** @param path the image to use for the sprite
** @param scene the scene to which the object will be added
** @return BGS_ERR_INPUT : object or path or scene is NULL
** @return BGS_ERR_PATH : the given path is bad
** @return BGS_ERR_MALLoc : malloc failed
** @return BGS_OK : the object is set to sprite and scene is update
**/
int object_set_sprite(object_t *object, char const *path, sfIntRect rect,
    sfVector2f pos);

/**
** @brief create UNSET object (you need to set it with object_set_* functions)
** And add it to the scene_t
** You can put NULL to update and display params if this object will be a
** text or a sprite
** You can put NULL to update and display if you don't want you object to
** be callable at each game loop
** @param update function called each game loop to update the object
** @param display function called each game loop to display the object
** @param scene the scene in which the object will be addded
** @return NULL : scene is NULL
** @return NULL : malloc failed
** @return object : the object is created
**/
object_t *create_object(
    void (*update)(object_t *, scene_t *, window_t *win, float),
    void (*display)(object_t *, dico_t *, dico_t *, sfRenderWindow *),
    scene_t *scene);

// ----------------------------------------------------------------------------
// create_scene.c
// ----------------------------------------------------------------------------

/**
** @brief create a scene and add it to window_t
** You can put NULL to create and destroy if you dont want to add a custom
** data to the scene
** You can put NULL to destroy and a valid function ot create if the create
** function don't malloc
** @param create function to create a custom data to add to the scene
** @param destroy function to destroy the custom data created
** @param win the window to which the scene will be added
** @return NULL : win is NULL
** @return NULL : malloc failed
** @return scene : the scene is created
**/
scene_t *create_scene(window_t *win, sfColor bg_color);

// ----------------------------------------------------------------------------
// loop.c
// ----------------------------------------------------------------------------

/**
** @brief launch the game (you have added a scene, and some object to it)
** @param win the window of the game
** @return BGS_ERR_INPUT : the scene index don't match any scene
** @return BGS_OK : the game is ended succesfully
** @return any other : some error
**/
int loop(window_t *win);

// ----------------------------------------------------------------------------
// object_add_components.c
// ----------------------------------------------------------------------------

/**
** @brief add a component to the dictionnary of components
** You can put NULL to destroy if the void *data dont need to be free
** @param object the object in which the component will be added
** @param data the data of the component
** @param key the key that represent the data
** @param destroy a function to destroy the void *data
** @return BGS_ERR_INPUT : object or datat or key is NULL
** @return BGS_ERR_MALLOC : malloc failed
** @return BGS_OK : the data is added
**/
int object_add_components(object_t *object, void *data, const char key[],
    void (*destroy)(void *));

int scene_add_components(scene_t *scene, void *data, const char key[],
    void (*destroy)(void *));

// ----------------------------------------------------------------------------
// remove.c
// ----------------------------------------------------------------------------

/**
** @brief destroy all scene attached to window, all object attached to scene,
** all components attached to an object
** @param win the window to destroy
**/
void remove_window(window_t *win);

// ----------------------------------------------------------------------------
// start.c
// ----------------------------------------------------------------------------

/**
** @brief toggle the VerticalSync
** (if disabled, enabled it) (if enable disbale it)
** @param win the winodw to toggle
**/
void window_toglle_vsync(window_t *win);

/**
** @brief set a frame rate limit to the render window
** @param win the window_t to set
** @param limit the limit of frame per seconds
**/
void window_set_framerate_limit(window_t *win, unsigned int limit);

/**
** @brief create the window_t, the main struct of the lib
** @param mode (CSFML) (sfVideoMode) {width, height Bits pre pixel}
** @param title the window title
** @return NULL : title is NULL
** @return NULL : malloc failed
** @return window : the window is created
**/
window_t *create_window(sfVideoMode mode, const char *title, sfUint32 style);

int scene_reload_lists(scene_t *scene);

void remove_object(object_t *object);

void remove_scene(scene_t *scene);

bool check_list(list_ptr_t *list, void *data);

#endif /* !BGS_H_ */
