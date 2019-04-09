/*
** my_strncmp.c for apojdazpo in /home/rechou_a/rendu/PSU/PSU_2015_minishell2/lib
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Sun Mar 27 15:41:28 2016 Benjamin RECHOU
** Last update Thu Apr 14 14:22:37 2016 Benjamin RECHOU
*/

int		my_strncmp(char *str1, char *str2, int n)
{
  int		i;

  i = 0;
  while (str1[i] && str2[i] && i != n)
    {
      if (str1[i] > str2[i])
	return (1);
      if (str1[i] < str2[i])
	return (1);
      i++;
    }
  return (0);
}

int		my_strcmp(char *str1, char *str2)
{
  int		i;

  i = 0;
  if (str1 && str2)
    {
      while (str1[1] && str2[i])
	{
	  if (str1[i] > str2[i])
	    return (1);
	  if (str1[i] < str2[i])
	    return (-1);
	  i++;
	}
      if (str1[i] == 0 && str2[i] == 0)
	return (0);
      if (str1[i] == 0)
	return (-1);
      return (1);
    }
  return (-1);
}
