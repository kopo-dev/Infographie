/*
** burn.c for ici on brûle des forêts et on fait en sorte que ça dure in /home/rechou_a/perso/ForestFire
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Thu Apr 21 00:26:06 2016 Benjamin RECHOU
** Last update Fri May  6 17:34:28 2016 Benjamin RECHOU
*/

#include "forest.h"

int		burning_neigh(char **tab, int i, int j)
{
  if (j - 1 >= 0 && tab[i][j + 1] != '\0')
    if ((tab[i][j - 1] == 'B') || (tab[i][j + 1] == 'B'))
      return (1);
  if (tab[i + 1] != NULL)
    {
      if (j - 1 >= 0 && tab[i][j + 1] != '\0')
	if ((tab[i + 1][j] == 'B') || (tab[i + 1][j + 1] == 'B') || (tab[i + 1][j - 1] == 'B'))
	  return (1);
    }
  if (i - 1 >= 0)
    {
      if (j - 1 >= 0 && tab[i][j + 1] != '\0')
	if ((tab[i - 1][j - 1] == 'B') || (tab[i - 1][j] == 'B') || (tab[i - 1][j + 1] == 'B'))
	  return (1);
    }
  return (0);
}

char		**update_field(char **field, int wfield, int hfield)
{
  char		**nfield;
  int		i;
  int		j;
  double		prob_t = 0.0153;
  double		prob_f = 0.000153;

  nfield = make_field(wfield, hfield);
  i = 0;
  while (field[i])
    {
      j = 0;
      while (j <= wfield)
	{
	  switch (field[i][j])
	    {
	    case ' ':
	      nfield[i][j] = prandom() > prob_t ? ' ' : 'T';
	      break;
	    case 'B':
	      nfield[i][j] = ' ';
	      break;
	    case 'T':
	      if (burning_neigh(field, i, j))
		nfield[i][j] = 'B';
	      else
		{
		  nfield[i][j] = prandom() > prob_f ? 'T' : 'B';
		}
	      break;
	    }
	  j++;
	}
      i++;
    }
  free_tab(field);
  return (nfield);
}
