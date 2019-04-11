/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** 
*/

int my_putchar(char);

int the_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
