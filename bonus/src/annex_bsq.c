/*
** EPITECH PROJECT, 2018
** annex_bsq
** File description:
** annex for the map wich will return the final map
*/

#include "my.h"

unsigned short **find_the_minim(unsigned short **tab, int i, int j)
{
    int save_min = tab[i][j - 1];

    if (tab[i - 1][j] < save_min)
        save_min = tab[i - 1][j];
    if (tab[i - 1][j - 1] < save_min)
        save_min = tab[i - 1][j - 1];
    tab[i][j] = save_min + 1;
    return (tab);
}

int save_values(tab_counter *tct_t, save_counter *sct_t,
                unsigned short **tab)
{
    if (tab[tct_t->i][tct_t->j] > tct_t->saver) {
        tct_t->saver = tab[tct_t->i][tct_t->j];
        sct_t->save_i = tct_t->i;
        sct_t->save_j = tct_t->j;
    }
}

unsigned short **advance_in_map(char *map,
                                unsigned short **tab, save_counter *sct_t)
{
    tab_counter tct_t;

    tct_t.saver = 0;
    tct_t.i = 1;
    tct_t.j = 1;
    for (int k = 0; map[k] != '\0'; k++) {
        if (map[k] == '.') {
            find_the_minim(tab, tct_t.i, tct_t.j);
            save_values(&tct_t, sct_t, tab);
        } else if (map[k] == '\n') {
            (tct_t.i)++;
            tct_t.j = 0;
        } else {
            tab[tct_t.i][tct_t.j] == 0;
        }
        (tct_t.j)++;
    }
    return (tab);
}

char *modifing_map(save_counter sct_t, unsigned short **tab, char **map,
                int nchar_line)
{
    int save = tab[sct_t.save_i][sct_t.save_j];
    int n = 0;
    int x;

    for (int nb_y = save; nb_y > 0; nb_y--) {
        n = 0;
        for (int nb_x = save; nb_x > 0; nb_x--) {
            x = (nchar_line + 1) * (sct_t.save_i - 1) + sct_t.save_j - n - 1;
            (*map)[x] = 'x';
            n++;
        }
        sct_t.save_i -= 1;
    }
    return (*map);
}

char *final_map(save_counter sct_t, unsigned short **tab, char *map,
                int nchar_line)
{
    int save = tab[sct_t.save_i][sct_t.save_j];
    int x;
    int n = 0;
    int k = 0;

    if (save >= 1)
        map = modifing_map(sct_t, tab, &map, nchar_line);
    return (map);
}
