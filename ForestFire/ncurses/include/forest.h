/*
** forest.h for Header for Forest Fire in /home/rechou_a/perso/ForestFire/include
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Tue Apr 19 15:51:13 2016 Benjamin RECHOU
** Last update Thu May  5 14:09:53 2016 Benjamin RECHOU
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
//#include <ncurses/curses.h>

#ifndef FOREST_H_
# define FOREST_H_

//main.c
double		prandom();

//burn.c
int		burning_neigh(char **tab, int i, int j);
char		**update_field(char **field, int wfield, int hfield);

//forest.c
char		**init_field(char **field, int wfield);
char		**make_field(int wfield, int hfield);


//basic lib
void		my_putchar(char c);
void		my_puterror(char *str);
void		my_putstr(char *str);
void		print_tab(char **tab);
void		*cmalloc(size_t size);
void		free_tab(char **tab);
int		my_strlen(char *str);

#endif /* FOREST_H_ */
