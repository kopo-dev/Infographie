/*
** my_path_to_wordtab.c for livacoupé in /home/rechou_a/lib/my_lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Thu Mar 24 16:05:59 2016 Benjamin RECHOU
** Last update Wed Apr  6 16:58:02 2016 Benjamin RECHOU
*/

#include <stdlib.h>
#include "lib.h"

static int		count_directories(char *str)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if ((str[i] == ':' && (str[i + 1] != ':' && str[i + 1] != '\0'))
	  || str[i + 1] == '\0')
	{
	  i++;
	  j++;
	}
      else
	i++;
    }
  return (j);
}

char			*set_path(char *str)
{
  int			i;
  int			j;
  char			*ret;

  i = 0;
  j = 0;
  ret = cmalloc(sizeof(char) * my_strlen(str));
  while (str[i] != '=')
    i++;
  i++;
  while (str[i])
    {
      ret[j] = str[i];
      i++;
      j++;
    }
  ret[j] = 0;
  return (ret);
}

static char			*my_memcpy(char *ret, char *str, int n)
{
  int			i;

  i = 0;
  while (i != n)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char			**my_path_to_wordtab(char *str)
{
  int			i;
  int			j;
  char			*path;
  char			**tab;

  j = 0;
  path = set_path(str);
  tab = cmalloc(sizeof(char *) * (count_directories(str) + 1));
  while (j != count_directories(str))
    {
      i = 0;
      while (path[i] != ':' && path[i] != 0)
	i++;
      if (i != 0)
	{
	  tab[j] = cmalloc(sizeof(char) * (i + 2));
	  my_memcpy(tab[j++], path, i);
	}
      path = path + 1 + i;
    }
  tab[j] = NULL;
  return (tab);
}
