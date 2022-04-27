/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** macro consts
*/

#ifndef MACROS_H_
    #define MACROS_H_

    #define LAYER_MAP 20
    #define LAYER_ENNEMY 5
    #define LAYER_PLAYER 3
    #define LAYER_MENUS 2
    #define LAYER_BUTTON 1
    #define LAYER_HUD 0

    #define GO_RT "0"
    #define GO_UP "1"
    #define GO_LT "3"
    #define GO_DN "2"

    #include <stdbool.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Vector2.h>

bool rect_contains_segment(
    sfFloatRect rect,
    sfVector2f point_a,
    sfVector2f point_b
);

#endif
