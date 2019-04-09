/*
** forest.c for partitiotime in /home/rechou_a/perso/ForestFire
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Thu Apr 21 00:19:12 2016 Benjamin RECHOU
** Last update Thu May  5 14:35:36 2016 Benjamin RECHOU
*/

#include "forest.h"

char		**init_field(char **field, int wfield)
{
  int		i;
  int		j;

  i = 0;
  while (field[i])
    {
      j = 0;
      while (j <= wfield)
	{
	  field[i][j] = ' ';
	  j++;
	}
      i++;
    }
  return (field);
}

char		**make_field(int wfield, int hfield)
{
  char		**field;
  int		i;

  i = 0;
  if ((field = malloc(sizeof(char *) * hfield + 1)) == NULL)
    exit(3);
  while (i < hfield)
    {
      if ((field[i] = malloc(sizeof(char) * wfield + 1)) == NULL)
	exit(3);
      field[i][wfield] = '\0';
      i++;
    }
  field[i - 1] = NULL;
  return(field);
}
