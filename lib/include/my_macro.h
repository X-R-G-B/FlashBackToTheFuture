/*
** EPITECH PROJECT, 2022
** LIBMACRO
** File description:
** some usefull macro
*/

#ifndef MY_MACRO_H_
    #define MY_MACRO_H_

// get the absolute value
    #define ABSOL(x) ((x) < 0) ? ((x) * -1) : (x)

// get the max
    #define MAX(x, y) ((x > y) ? (x) : (y))

// get the min
    #define MIN(x, y) ((x < y) ? (x) : (y))

// return bool with only 0 or 1
    #define TOBOOL(x) (((x) == 0) ? 0 : 1)

// NOT logic
    #define NOT(x) (((x) == 0) ? 1 : 0)

#endif
