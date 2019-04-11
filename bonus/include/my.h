/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** proto file
*/

#ifndef MY_
#define MY_
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);

int gest_error(int fd, off_t size, char **map, save_counter *sct_t);
int gest_error2(int fd, char *map, off_t size);
int check_map(char *map);
void gest_error_of_map(char *map, int fnb_line);

int my_ctoi(char c);
int my_bsq_atoi(char **str);
int my_bsq_count_char(char *str);
off_t find_size_of_file(char const *filepath);
unsigned short **memset_map(char const *filepath, char **map, int *nchar_line);

unsigned short **find_the_minim(unsigned short **tab, int i, int j);
int save_values(tab_counter *t_ct, save_counter *s_ct, unsigned short **tab);
unsigned short **advance_in_map(char *map, unsigned short **tab,
                                save_counter *s_ct);
char *modifing_map(save_counter s_ct, unsigned short **tab, char **map,
                    int nchar_line);
char *final_map(save_counter s_ct, unsigned short **tab, char *map,
                int nchar_line);
#endif
