/*
** get_next_line.c for markIII in /home/rechou_a/rendu/GetNextLine
** 
** Made by Benjamin RÉCHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Thu Jan 14 14:13:28 2016 Benjamin RÉCHOU
** Last update Thu Apr 14 14:52:15 2016 Benjamin RECHOU
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int				get_len(char *str)
{
  int				i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char				*my_realloc(char *line, int size)
{
  char				*tempo;
  int				i;

  i = 0;
  if ((tempo = malloc(READ_SIZE + size)) == NULL)
    return (NULL);
  if (line == NULL)
    return (tempo);
  else
    {
      while (line[i])
	{
	  tempo[i] = line[i];
	  i++;
	}
      tempo[i] = '\0';
    }
  free(line);
  return (tempo);
}

char				*get_reste(char *buf, int i)
{
  char				*tempo;
  int				i_tem;

  i_tem = 0;
  if ((tempo = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  while (buf[i])
    {
      tempo[i_tem] = buf[i];
      i++;
      i_tem++;
    }
  tempo[i_tem - 1] = '\0';
  return (tempo);
}

char				*buff_anal(char *buf)
{
  static char			*reste = NULL;
  char				*ret;
  static int			i_res = 0;
  int				i;

  i = 0;
  if ((reste == NULL) && ((reste = malloc(READ_SIZE + 1)) == NULL))
      return (NULL);
  else
    {
      reste = my_realloc(reste, READ_SIZE + (get_len(reste)));
      i_res = get_len(reste);
    }
  while ((buf[i] != '\n') && (buf[i] != '\0'))
    reste[i_res++] = buf[i++];
  reste[i_res] = '\0';
  if (buf[i] == '\n')
    {
      ret = reste;
      reste = get_reste(buf, i);
      i_res = 0;
      return (ret);
    }
  return (NULL);
}

char				*get_next_line(const int fd)
{
  char				*buf;
  int				ret;
  char				*test;

  if ((buf = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  buf[READ_SIZE] = '\0';
  while ((ret = read(fd, buf, READ_SIZE)) > 0)
    {
      buf[ret] = '\0';
      test = buff_anal(buf);
      if (test != NULL)
	return (test);
    }
  return (NULL);
}
