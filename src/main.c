/*
** main.c for main in /home/artha/lib_next
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 20:19:55 2017 dylan renard
** Last update Sun Jan 22 20:42:08 2017 dylan renard
*/

#include "shell.h"

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  if (s1 == NULL || s2 == NULL)
    return (-2);
  i = 0;
  while ((*(s1 + i) != '\0' && *(s1 + i) == *(s2 + i)) && i != n)
    i = i + 1;
  if (*(s1 + i) > *(s2 + i))
    return (1);
  else if (*(s1 + i) < *(s2 + i))
    return (-1);
  return (0);
}

static char	**init_env(void)
{
  char		**envp;

  envp = malloc(4 * sizeof(char *));
  envp[0] = my_strdup("PATH=/bin/");
  envp[1] = my_strdup("HOME=/");
  envp[2] = my_strdup("NAME=artha");
  envp[3] = NULL;
  return (envp);
}

int		main(void)
{
  char		*str;
  char		**command;
  char		**envp;

  envp = init_env();
  my_putstr("$>");
  while ((str = get_next_line(0)) != NULL)
    {
      command = my_str_to_wordtab(str);
      if (my_strcmp(command[0], "exit") == 0)
	x_exit(command, envp);
      else if (my_strcmp(command[0], "cd") == 0)
	x_cd(command, envp);
      else if (my_strcmp(command[0], "env") == 0)
	envp = x_env(command, envp);
      else if (my_strcmp(command[0], "setenv") == 0)
	envp = x_setenv(command, envp);
      else if (my_strcmp(command[0], "unsetenv") == 0)
	envp = x_unsetenv(command, envp);
      else if (command[0] != NULL)
	xexecve(my_strcat(get_env("PATH", envp), command[0]), command, envp);
      my_putstr("$>");
      free(str);
    }
  return (0);
}
