/*
** my_revstr.c for lib_next in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 21:05:30 2017 dylan renard
** Last update Sun Jan 22 21:05:31 2017 dylan renard
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	len;
  int	i;
  char	tmp;

  len = my_strlen(str) - 1;
  i = 0;
  while (i < len)
    {
      tmp = *(str + i);
      *(str + i) = *(str + len);
      *(str + len) = tmp;
      len = len - 1;
      i = i + 1;
    }
  return (str);
}
