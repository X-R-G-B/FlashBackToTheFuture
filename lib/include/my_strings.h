/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** header of the strings part
*/

#ifndef MY_STRINGS_H_
    #define MY_STRINGS_H_

/**
** @brief malloc n block and fill it with \0
** @param n
** @return null if cannot malloc; the new char * otherwise
**/
char *my_calloc(int n);

/**
** @brief reverse str inplace
** @param str
** @return null if str is null; otherwise str
**/
char *my_revstr(char *str);

/**
** @brief add chars of src at the \0 of dest
** @param dest
** @param src
** @return null if dest is null; otherwise dest
**/
char *my_strcat(char *dest, char const *src);

/**
** @brief compare s1 and s2 char per char
** @param s1
** @param s2
** @return 0 if s1 equal s2; otherwise the difference between s1[x] and s2[x]
**/
int my_strcmp(char const *s1, char const *s2);

/**
** @brief check if substr is in str
** @param str
** @param substr
** @return 1 if substr is in str; 0 otherwise
**/
int my_strcontains(char const *str, char const *substr);

/**
** @brief check if str contain c
** @param str
** @param c
** @return 1 if c is in str; 0 otherwise
**/
int my_strcontainc(char const *str, char const c);

/**
** @brief copy str in dest and add \0 at the end
** @param dest
** @param src
** @return null if src is null; otherwise dest
**/
char *my_strcpy(char *dest, char const *src);

/**
** @brief duplicate str (with malloc) and add a \0 at the end
** @param str
** @return NULL if str equal null or cannot malloc; else the duplicated str
**/
char *my_strdup(char const *str);

/**
** @brief get lentgh of null terminated str
** @param str
** @return -1 if str is null; else the length
**/
int my_strlen(char const *str);

/**
** @brief check if str start with substr
** @param str
** @param substr
** @return 1 if str start with substr; 0 otherwise
**/
int my_strstartswith(char const *str, char const *substr);

#endif
