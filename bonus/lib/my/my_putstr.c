/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** put strings
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

void x_point_and_o(char const *str, int *nb_line, int *save_the_last_x, int i);

int cond_in(char const *str, int *nb_line, int save_the_last_x, int i);

void disp_message(int save_the_first_x, int save_the_last_x);

int cpt_int_len(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb = -nb;
        len += 1;
    }
    while (nb > 0) {
        nb = nb / 10;
        len += 1;
    }
    return (len);
}

int count_line(int save_line, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            save_line++;
    return (save_line);
}

void disp_nb_espaces(int save_line, int nb_line)
{
    for (int s_line = cpt_int_len(save_line) - cpt_int_len(nb_line) + 1; s_line > 0; s_line--)
        my_putchar(' ');
}

int my_putstr(char const *str)
{
    int save_line = 0;
    int i;
    int size;
    int nb_line = 1;
    int save_the_last_x;
    int save_the_first_x = -1;

    if (str == NULL)
        return (84);
    save_line = count_line(save_line, str);
    the_putstr(PURPULE);
    my_put_nbr(nb_line);
    disp_nb_espaces(save_line, nb_line);    
    for (int  i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'x' && save_the_first_x == -1)
            save_the_first_x = nb_line;
        save_the_last_x = cond_in(str, &nb_line, save_the_last_x, i);
    }
    disp_message(save_the_first_x, save_the_last_x);
    return (1);
}
