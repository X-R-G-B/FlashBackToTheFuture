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
**
** @param win window in which the scene will be added
** @param scene scene to add to the window
**
** @return {
** BGS_ERR_INPUT : win or scene is NULL,
** BGS_ERR_MALLOC : malloc failed,
** BGS_OK : the scene has been added
** }
**/
int window_add_scene(window_t *win, scene_t *scene);

/**
** @brief add an object_t to a scene_t
**
** @param scene scene in which the object will be added
** @param object object to add to the scene
**
** @return {
** BGS_ERR_INPUT : scene or object is NULL,
** BGS_ERR_MALLOC : malloc failed,
** BGS_OK : the object has been added
** }
**/
int scene_add_object(scene_t *scene, object_t *object);

// ----------------------------------------------------------------------------
// create_object.c
// ----------------------------------------------------------------------------

/**
** @brief setup an object_t to be a music
**
** @param object object to setup
** @param path path to the music (.ogg is better)
** @param play_now indicate if the music need to be played just after creation
** @param loop_now indicate if the music need to be looped
**
** @return {
** BGS_ERR_INPUT : object ot path is NULL,
** BGS_ERR_PATH : path to the music is bad,
** BGS_OK : the object has been setup
** }
**/
int object_set_audio(object_t *object, char const *path, bool play_now,
    bool loop_now);

/**
** @brief setup an object_t to be a custom object
**
** @param object object to setup
**
** @return {
** BGS_ERR_INPUT : object is NULL,
** BGS_OK : the object has been setup
** }
**/
int object_set_custom(object_t *object);

/**
** @brief setup an object_t to be a text
**
** @param object object to setup
** @param path path to the font for the text
** @param text default text to display
** @param pos default position on the screen
**
** @return {
** BGS_ERR_INPUT : object or path or text is NULL,
** BGS_ERR_PATH : path to the font is bad,
** BGS_ERR_MALLOC : malloc failed,
** BGS_OK : the object has been setup
** }
**/
int object_set_text(object_t *object, char const *path, char const *text,
    sfVector2f pos);

/**
** @brief setup an object_t to be a sprite
**
** @param object object to setup
** @param path path to the texture
** @param rect rectangle to use; could be {-1, -1, -1, -1} to fit all the image
** @param pos default position on the screen
**
** @return {
** BGS_ERR_INPUT : object or path is NULL,
** BGS_ERR_PATH : path to the texture is bad,
** BGS_ERR_MALLOC : malloc failed,
** BGS_OK : the object has been setup
** }
**/
int object_set_sprite(object_t *object, char const *path, sfIntRect rect,
    sfVector2f pos);

/**
** @brief create an object that will need to be setup (object_set_* funcs)
**
** NB:
** update: can be equal NULL if you dont need it
** display: can be equal NULL; if you set the object to text or sprite,
** the lib will provide a default pre-set function
**
** @param update function to call at each game loop for the scene
** @param display function call to display the object
** @param scene scene in which the object belongs
**
** @return {
** NULL : scene is NULL,
** NULL : malloc failed
** object_t *: the object has been created
** }
**/
object_t *create_object(
    void (*update)(object_t *, scene_t *, window_t *win, float),
    void (*display)(object_t *, dico_t *, dico_t *, sfRenderWindow *),
    scene_t *scene);

// ----------------------------------------------------------------------------
// create_scene.c
// ----------------------------------------------------------------------------

/**
** @brief create a scene_t and add it to the window's scene_t list
**
** @param win window in which the scene will be added
** @param bg_color color to use when clear the window at each frame
**
** @return {
** NULL : win is NULL,
** NULL : malloc failed,
** scene_t *: the scene has been created
** }
**/
scene_t *create_scene(window_t *win, sfColor bg_color);

// ----------------------------------------------------------------------------
// loop.c
// ----------------------------------------------------------------------------

/**
** @brief loop the game until the end
**
** @param win window to play
**
** @return {
** BGS_ERR_INPUT : win is NULL,
** BGS_ERR_INPUT : scene_index is bad,
** BGS_OK : game ended successfully,
** any other int : not registered errors
** }
**/
int loop(window_t *win);

// ----------------------------------------------------------------------------
// object_add_components.c
// ----------------------------------------------------------------------------

/**
** @brief add a components to the object_t's components
**
** @param object object in which the components will be added
** @param data components value
** @param key key to get the value
** @param destroy function to call when the components need to be destroy
**
** @return {
** BGS_ERR_INPUT : object ot data or key is NULL,
** BGS_ERR_MALLOC : malloc failed,
** BGS_OK : the components has been added
** }
**/
int object_add_components(object_t *object, void *data, const char key[],
    void (*destroy)(void *));

int scene_add_components(scene_t *scene, void *data, const char key[],
    void (*destroy)(void *));

// ----------------------------------------------------------------------------
// remove.c
// ----------------------------------------------------------------------------

/**
** @brief destroy all that is inside this window_t
**
** @param win window to destroy / exterminated
**/
void remove_window(window_t *win);

// ----------------------------------------------------------------------------
// start.c
// ----------------------------------------------------------------------------

/**
** @brief toggle the Vertical Sync for a window_t
**
** @param win window to toggle
**/
void window_toglle_vsync(window_t *win);

/**
** @brief set a frame rate limit to a window_t
**
** @param win window to set frame rate limit
** @param limit limit of frame per seconds
**/
void window_set_framerate_limit(window_t *win, unsigned int limit);

/**
** @brief create a window_t
**
** @param mode mode to use {width, height, Bits per pixel}
** @param title window title
** @param style style of the window (sfResize / sfClosed / sfFullScreen)
**
** @return {
** NULL : title is NULL,
** malloc failed,
** window_t *: the window has been created
** }
**/
window_t *create_window(sfVideoMode mode, const char *title, sfUint32 style);

/**
** @brief reload configs of object_t of a scene_t
**
** @param scene scene to reload
**
** @return {
** BGS_ERR_INPUT : scene is NULL or scene's object list can't be reset
** BGS_ERR_MALLOC : malloc failed
** BGS_OK : the scene has been reloaded
** }
**/
int scene_reload_lists(scene_t *scene);

/**
** @brief remove an object (might cause segv)
**
** use list_add_to_start(scene->to_remove, object) instead
**
** @param object object to destroy
**/
void remove_object(object_t *object);

/**
** @brief remove a scene (might cause segv)
**
** use list_add_to_start(window->to_remove, scene) instead
**
** @param scene scene to destroy
**/
void remove_scene(scene_t *scene);

/**
** @brief check and remove link if data is in list
**
** @param list list in which data can be
** @param data data to remove link in the list
**
** @return {
** true : data is in the list,
** false : data is not in the list
** }
**/
bool check_list(list_ptr_t *list, void *data);

#endif /* !BGS_H_ */
