/*
** main.c for solo cette ois ci in /home/rechou_a/perso/ForestFire
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Wed Apr 20 02:00:47 2016 Benjamin RECHOU
** Last update Wed May 11 17:22:04 2016 Benjamin RECHOU
*/

#include "forest.h"

double		prandom()
{
  return((double)rand() / RAND_MAX);
}

WINDOW		*display(char **field, int wfield, int hfield, int  r0, int  r1, int  r2, int  r3 , int  r4 , int  r5)
{
  WINDOW	*wf;
  int		i;
  int		j;

  wf = newwin(hfield, wfield, 0, 0);
  start_color();
  init_pair(1, r0, r1);
  init_pair(2, r2, r3);
  init_pair(3, r4, r5);
  i = 0;
	  
  while (field[i])
    {
      j = 0;
      while (j < wfield)
	{
	  switch (field[i][j])
	    {
	    case ' ':
	      wattron(wf, COLOR_PAIR(1));
	      mvwprintw(wf, i, j, " ");
	      wattroff(wf, COLOR_PAIR(1));
	      break;
	    case 'B':
	      wattron(wf, COLOR_PAIR(3));
	      mvwprintw(wf, i, j, "T");
	      wattroff(wf, COLOR_PAIR(3));
	      break;
	    case 'T':
	      wattron(wf, COLOR_PAIR(2));
	      mvwprintw(wf, i, j, "T");
	      wattroff(wf, COLOR_PAIR(2));
	      break;
	    }
	  j++;
	}
      i++;
    }
  return (wf);
}

int		main(int argc, char **argv)
{
  WINDOW	*wf;
  char		**field;
  int		wfield;
  int		hfield;
  int		r0;
  int		r1;
  int		r2;
  int		r3;
  int		r4;
  int		r5;
  int		i;

  srand(time(NULL));

  r0 = rand() % 8 + 1;
  r1 = rand() % 8 + 1;
  r2 = rand() % 8 + 1;
  r3 = rand() % 8 + 1;
  r4 = rand() % 8 + 1;
  r5 = rand() % 8 + 1;
  i = 0;

  wfield = 220; //220 190; xterm differ
  hfield = 70; // 70 60;
  (void)argc;
  (void)argv;
  clear();
  initscr();
  curs_set(0);
  field = make_field(wfield, hfield);
  field = init_field(field, wfield);
  while (i != 5000)
    {
      field = update_field(field, wfield, hfield);
      wf = display(field, wfield, hfield, r0, r1, r2, r3, r4, r5);
      usleep(50000);
      wrefresh(wf);
      i++;
    }
  free_tab(field);
  endwin();
  return (1);
}
