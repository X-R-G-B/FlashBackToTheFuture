/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** example sound buffer
*/

#include <SFML/Graphics/Color.h>
#include <stdbool.h>
#include "my_puts.h"
#include "my_bgs.h"

int main(void)
{
    window_t *win = create_window((sfVideoMode) {800, 600, 32}, "test",
            sfClose);
    scene_t *scene = create_scene(win, sfBlack, "SALUT");
    object_t *obj = create_object(NULL, NULL, scene, 0);

    object_set_sound(obj, "./tests/click-effect.ogg", true, true);
    window_change_scene(win, "SALUT");
    loop(win);
    remove_window(win);
    return (0);
}
