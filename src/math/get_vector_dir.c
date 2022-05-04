/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** get the vector between two point
*/

#include <stdlib.h>
#include <SFML/System/Vector2.h>

sfVector2f get_vector_dir(sfVector2f point_a, sfVector2f point_b, float coef)
{
    sfVector2f new = {
        (point_a.x - point_b.x) * coef,
        (point_a.y - point_b.y) * coef
    };
    return (new);
}

sfVector2f *get_vector_dir_malloc(sfVector2f point_a, sfVector2f point_b,
    float coef)
{
    sfVector2f *new = NULL;
    sfVector2f dir = {0};

    printf("in calc player: %f %f ennemy: %f %f\n", point_a.x, point_a.y, point_b.x, point_b.y);
    //here we calculate the vector with GOOD value in input
    new = malloc(sizeof(sfVector2f));
    if (new == NULL) {
        return (NULL);
    }
    dir = get_vector_dir(point_a, point_b, coef);
    new->y = dir.y;
    new->x = dir.x;
    return (new);
}
