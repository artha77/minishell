/*
** xfunc.c for mysh in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 15:14:49 2017 dylan renard
** Last update Sun Jan 22 20:38:01 2017 dylan renard
*/

#include "shell.h"

char		**x_cd(char **av, char **envp)
{
  int		ac;

  ac = len_env(av);
  if (ac != 2)
    return (my_puts_fd("cd [PATH]", 2), envp);
  cd(av[1]);
  return (envp);
}

char		**x_setenv(char **av, char **envp)
{
  int		ac;

  ac = len_env(av);
  if (ac > 3)
    return (my_puts_fd("setenv [VAR_NAME] [VALUE]", 2), envp);
  else if (ac == 3)
    envp = set_env(av[1], av[2], envp);
  else if (ac == 2)
    envp = set_env(av[1], NULL, envp);
  else if (ac == 1)
    display_env(envp);
  return (envp);
}

char		**x_unsetenv(char **av, char **envp)
{
  int		ac;

  ac = len_env(av);
  if (ac != 2)
    return (my_puts_fd("unsetenv [VAR_NAME]", 2), envp);
  envp = unset_env(av[1], envp);
  return (envp);
}

char		**x_env(char **av, char **envp)
{
  int		ac;

  ac = len_env(av);
  if (ac == 1)
    display_env(envp);
  else if (ac == 2)
    envp = set_env(find_name(av[1]), find_value(av[1]), envp);
  else if (ac == 3 && (my_strcmp(av[1], "-u") == 0))
    envp = unset_env(av[2], envp);
  return (envp);
}

char		**x_exit(char **av, char **envp)
{
  free(av);
  free(envp);
  exit(0);
}
