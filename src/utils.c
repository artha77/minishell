/*
** utils.c for mysh in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 20:05:55 2017 dylan renard
** Last update Sun Jan 22 20:07:19 2017 dylan renard
*/

#include "shell.h"

char		*find_name(char *str)
{
  char		*final;
  int		i;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '=')
    {
      if (str[i] == '\0')
	return (NULL);
      i++;
    }
  i = 0;
  if ((final = malloc((i + 1) * sizeof(char))) == NULL)
    exit(84);
  while (str[i] != '=')
    {
      final[i] = str[i];
      i++;
    }
  final[i] = '\0';
  return (final);
}

char		*find_value(char *str)
{
  char		*final;
  int		i;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '=')
    {
      if (str[i] == '\0')
	return (NULL);
      i++;
    }
  return (my_strdup(str + i + 1));
}
