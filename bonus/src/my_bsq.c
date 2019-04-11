/*
** EPITECH PROJECT, 2018
** my_bsq
** File description:
** bsq principal fct
*/

#include "my.h"

void last_action(char *save_map, char *map, unsigned short **tab, int fd)
{
    int i;

    my_putstr(map);
    free(save_map);
    for (i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    close(fd);
}

int my_bsq(char const *filepath)
{
    save_counter sct_t;
    int nchar_line;
    int fd = open(filepath, O_RDONLY);
    off_t size = find_size_of_file(filepath);
    char *map = malloc(sizeof(char) * (size + 1));
    char *save_map = map;
    unsigned short **tab;

    if (gest_error(fd, size, &map, &sct_t) == 84)
        return (84);
    if (gest_error2(fd, map, size) == 84)
        return (84);
    tab = memset_map(filepath, &map, &nchar_line);
    if (check_map(map) == 84)
        return (84);
    tab = advance_in_map(map, tab, &sct_t);
    map = final_map(sct_t, tab, map, nchar_line);
    last_action(save_map, map, tab, fd);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
        return (my_bsq(av[1]));
    else
        return (84);
    return (0);
}
