/*
** cmalloc.c for because I'm lazyyy in /home/rechou_a/lib/my_lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Thu Mar 24 16:13:29 2016 Benjamin RECHOU
** Last update Thu May  5 15:24:04 2016 Benjamin RECHOU
*/

#include <stdlib.h>

void			*cmalloc(size_t size)
{
  void			*p;

  p = malloc(size);
  if (p == 0)
    exit(1);
  else
    return (p);
}

void			free_tab(char	**tab)
{
  int			i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
