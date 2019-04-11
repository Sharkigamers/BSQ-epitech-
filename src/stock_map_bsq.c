/*
** EPITECH PROJECT, 2018
** annex_bsq
** File description:
** annex for fsq
*/

#include "my.h"

int my_ctoi(char c)
{
    return (c - '0');
}

int my_bsq_atoi(char **str)
{
    int i;
    int nb = 0;

    for (i = 0; (*str)[i] != '\n' && (*str)[i] != '\0'; i++) {
        if ((*str)[i] >= '0' && (*str)[i] <= '9')
            nb = (nb * 10) + my_ctoi((*str)[i]);
        else
            exit (84);
    }
    i++;
    (*str) += i;
    return (nb);
}

int my_bsq_count_char(char *str)
{
    int i;

    for (i = 0; str[i] != '\n' && str[i] != '\0'; i++);
    return i;
}

off_t find_size_of_file(char const *filepath)
{
    struct stat buf;
    off_t size;

    stat(filepath, &buf);
    if (stat(filepath, &buf) == -1)
        exit (84);
    size = buf.st_size;
    return size;
}

unsigned short **memset_map(char const *filepath, char **map, int *nchar_line)
{
    int fnb_line;
    unsigned short **tab;
    int i;

    fnb_line = my_bsq_atoi(map);
    gest_error_of_map(*map, fnb_line);
    if (fnb_line < 0)
        exit (84);
    *nchar_line = my_bsq_count_char(*map);
    tab = malloc(sizeof(short *) * (fnb_line + 2));
    for (i = 0; i != (fnb_line + 1); i++) {
        tab[i] = malloc(sizeof(short *) * (*nchar_line + 1));
        for (int j = 0; j != (*nchar_line + 1); j++) {
            tab[i][j] = 0;
        }
    }
    tab[i] = NULL;
    return (tab);
}
