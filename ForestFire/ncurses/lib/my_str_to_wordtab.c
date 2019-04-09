/*
** my_str_to_wordtab.c for oui in /home/rechou_a/rendu/PSU/PSU_2015_minishell2/lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Tue Apr  5 14:02:43 2016 Benjamin RECHOU
** Last update Thu Apr 14 20:50:11 2016 Benjamin RECHOU
*/

#include "lib.h"

int		count_tab(char **cmd_tab)
{
  int		i;

  i = 0;
  while (cmd_tab[i])
    i++;
  return (i);
}

static int			count_str(char *str)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  j++;
	}
      i++;
    }
  if (str[0] != ' ' && str[0] != '\t')
    j++;
  if (str[my_strlen(str) - 1] == ' ' || str[my_strlen(str) - 1] == '\t')
    j--;
  return (j);
}

static char		*my_memcpy(char *ret, char *src, int n)
{
  int			i;

  i = 0;
  while (i != n)
    {
      ret[i] = src[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char			**magic_is_gay(char *str, char *p)
{
  int			i;
  int			n;
  int			c;
  char			**tab;

  n = 0;
  tab = cmalloc(sizeof(char *) * (count_str(str) + 1));
  while (n != count_str(str))
    {
      i = 0;
      c = 0;
      while (p[i] != ' ' && p[i] != '\t' && p[i])
	{
	  i++;
	  c++;
	}
      if (c != 0)
	{
	  tab[n] = cmalloc(sizeof(char) * (c + 1));
	  my_memcpy(tab[n++], p, c);
	}
      p = p + i + 1;
    }
  tab[n] = NULL;
  return (tab);
}

char			**my_str_to_wordtab(char *str)
{
  char			*p;
  char			**tab;

  p = str;
  tab = magic_is_gay(str, p);
  return (tab);
}
