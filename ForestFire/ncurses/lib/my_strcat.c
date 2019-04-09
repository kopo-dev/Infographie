/*
** my_strcat.c for str_cat in /home/rechou_a/rendu/PSU/PSU_2015_minishell2/lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Mon Apr  4 20:43:53 2016 Benjamin RECHOU
** Last update Thu Apr  7 04:42:57 2016 Benjamin RECHOU
*/

#include "lib.h"

char		*my_strcat(char *st1, char *st2)
{
  int		i;
  int		j;
  int		new_size;
  char		*str;

  i = 0;
  j = 0;
  new_size = my_strlen(st1) + my_strlen(st2);
  if ((str = malloc(sizeof(char) * new_size + 1)) == NULL)
    return (NULL);
  while (st1[i])
    {
      str[i] = st1[i];
      i++;
    }
  while (st2[j])
    {
      str[i] = st2[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}

