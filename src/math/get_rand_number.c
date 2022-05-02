/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** get rand number
*/

#include <stdlib.h>
#include <time.h>

int randomise(int min, int max)
{
    int number = 0;

    time(0);
    number = (rand() % (max - min + 1)) + min;
    return (number);
}
