/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** put strings
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int size;

    if (str == NULL)
        return (84);
    size = my_strlen(str);
    if (write(1, str, size) == -1)
        return (84);
    return (1);
}
