/*
** my_strdup.c for nononononoonnoonononononoonono in /home/rechou_a/rendu/PSU/PSU_2015_minishell2/lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Sun Mar 27 13:26:17 2016 Benjamin RECHOU
** Last update Wed Apr 20 15:46:49 2016 Benjamin RECHOU
*/

#include "forest.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

char		*my_strdup(char *str)
{
  char		*ret;
  int		i;
  int		len;

  i = 0;
  len = my_strlen(str);
  ret = cmalloc(sizeof(char) * len + 1);
  while (str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}
