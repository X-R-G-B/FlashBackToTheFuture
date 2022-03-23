/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** the conversions part of libmy
*/

#ifndef MY_CONVERSIONS_H_
    #define MY_CONVERSIONS_H_

/**
** @brief get the number in str
** @param str
** @return the number (0 if it not a number (my_atoi_err))
**/
int my_atoi(char const *str);
float my_atof(char const *str);
double my_atodf(char const *str);

/**
** @brief get the number in str
** @param str
** @param is_error
** @return 0 if there is an error and *is_error set to 1; the number else
**/
int my_atoi_err(char const *str, int *is_error);
float my_atof_err(char const *str, int *is_error);
double my_atodf_err(char const *str, int *is_error);

/**
** @brief int to str in base 10
** @param nb
** @return null if there is error; the str else
**/
char *my_itoa(int nb);

/**
** @brief int to str base base if base not null
** @param nb
** @param base
** @return null if error; else the str
**/
char *my_itoa_base(int nb, char const *base);

/**
** @brief int to str in base base if base is not null
** @param nb
** @param base
** @param is_error
** @return *is_error set to 1 if error; otherwise the str
**/
char *my_itoa_base_err(int nb, char const *base, int *is_error);

/**
** @brief int to str in base 10
** @param nb
** @param is_error
** @return null if there is error; else the str
**/
char *my_itoa_err(int nb, int *is_error);

#endif
