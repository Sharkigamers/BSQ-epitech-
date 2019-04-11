/*
** EPITECH PROJECT, 2018
** annex_putstr
** File description:
** annex for the putstr
*/

#include <unistd.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\x1B[0m"
#define PURPULE "\033[1;35m"

void my_putchar(char);

int the_putstr(char const *str);

int my_put_nbr(int nb);

int my_strlen(char const *str);

void disp_nb_espaces(int save_line, int nb_line);

void x_point_and_o(char const *str, int *nb_line, int *save_the_last_x, int i)
{
    if (str[i] == 'x') {
        *save_the_last_x = (*nb_line);
        the_putstr(GREEN);
        my_putchar(str[i]);
        the_putstr(RESET);
    }
    if (str[i] == 'o') {
	the_putstr(RED);
        my_putchar(str[i]);
        the_putstr(RESET);
    }
    if (str[i] == '.') {
        the_putstr(BLUE);
        my_putchar(str[i]);
        the_putstr(RESET);
    }
}

int cond_in(char const *str, int *nb_line, int save_the_last_x, int i)
{
    int save_line = 0;

    the_putstr(RESET);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            save_line++;
    x_point_and_o(str, nb_line, &save_the_last_x, i);
    if (str[i] == '\n') {
        my_putchar('\n');
        (*nb_line)++;
        the_putstr(PURPULE);
        my_put_nbr(*nb_line);
        the_putstr(RESET);
        disp_nb_espaces(save_line, *nb_line);
    }
    return (save_the_last_x);
}

void disp_message(int save_the_first_x, int save_the_last_x)
{
    the_putstr(GREEN);
    write(1, "The start of the square is at the line : ", 42);
    my_put_nbr(save_the_first_x);
    write(1, " and the end of the square is at the line : ", 44);
    my_put_nbr(save_the_last_x);
    write(1, " , then, it's a square of : ", 28);
    my_put_nbr(save_the_last_x - save_the_first_x + 1);
    write(1, " by ", 4);
    my_put_nbr(save_the_last_x - save_the_first_x + 1);
}
