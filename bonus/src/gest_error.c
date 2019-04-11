/*
** EPITECH PROJECT, 2018
** gest_error
** File description:
** gest the errorrs
*/

#include "my.h"

int gest_error(int fd, off_t size, char **map, save_counter *sct_t)
{

    sct_t->save_i = 0;
    sct_t->save_j = 0;
    if (fd == -1)
        return (84);
    if (size == 0)
        return (84);
    (*map)[size] = '\0';
    return (0);
}

int gest_error2(int fd, char *map, off_t size)
{
    if (read(fd, map, size) == -1)
        return (84);
    if (map[size - 1] == 0)
        return (84);
    return (0);
}

int check_map(char *map)
{
    int save_i = 0;
    int n = 0;

    for (int i = 0; map[i] != '\n' && map[i] != '\0'; i++)
        save_i = i + 1;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n' && ((i - n) % save_i) != 0) {
            return (84);
        }
        if (map[i] == '\n')
            n++;
        if (map[i] != '\n' && map[i] != '.' && map[i] != 'o')
            return (84);
    }
}

void gest_error_of_map(char *map, int fnb_line)
{
    int count_line = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            count_line++;
    }
    if (fnb_line != count_line)
        exit (84);
}
