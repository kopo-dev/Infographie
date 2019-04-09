/*
** print.c for oui in /home/rechou_a/rendu/PSU/PSU_2015_minishell2/lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Fri Apr  1 17:51:08 2016 Benjamin RECHOU
** Last update Wed Apr 20 15:46:20 2016 Benjamin RECHOU
*/

#include "forest.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		print_tab(char **tab)
{
  int		i;
  int		j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  my_putchar(tab[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}
