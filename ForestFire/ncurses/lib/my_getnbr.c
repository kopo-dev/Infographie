/*
** my_getnbr.c for my_getnbr in /home/rechou_a/rendu/Piscine_C_colles-Semaine_02
** 
** Made by Benjamin RÉCHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Sat Oct 10 15:56:22 2015 Benjamin RÉCHOU
** Last update Tue Apr 12 22:38:42 2016 Benjamin RECHOU
*/

#include "lib.h"

int		get_lim(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  return (i);
}

int             is_neg(char *str)
{
  int           i;
  int           counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        counter++;
      i++;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

int             is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

int             my_getnbr(char *str)
{
  int           i;
  int           nbr;

  nbr = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
