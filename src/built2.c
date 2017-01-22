/*
** built2.c for mysh in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 14:59:21 2017 dylan renard
** Last update Sun Jan 22 21:02:58 2017 dylan renard
*/

#include "shell.h"

void		display_env(char **envp)
{
  int		i;

  if (envp == NULL)
    return ;
  i = -1;
  while (envp[i] != NULL)
    {
      my_putstr(envp[++i]);
      if (envp[i] != NULL)
	my_putchar('\n');
    }
}

int		env_pos(char *name, char **envp)
{
  int		j;
  int		len;
  int		cmp;

  j = 0;
  len = custom_len(envp[j], '=');
  while (envp[j] != NULL)
    {
      cmp = my_strncmp(name, envp[j], len - 1);
      if (cmp == 0)
	{
	  return (j);
	}
      else
	{
	  j++;
	  len = custom_len(envp[j], '=');
	}
    }
  return (-1);
}

char		**unset_env(char *name, char **envp)
{
  char		**envp_new;
  int		j;
  int		k;
  int		pos;

  k = -1;
  pos = env_pos(name, envp);
  j = 0;
  if (pos == -1)
    return (my_puts_fd(my_strcat(name, " doesn't exist"), 2), envp);
  else
    {
      if ((envp_new = malloc(len_env(envp) * sizeof(char *))) == NULL)
	exit(84);
      envp_new[len_env(envp) - 1] = NULL;
      while (envp[j] != NULL)
	{
	  if (j != pos)
	    envp_new[++k] = envp[j];
	  j++;
	}
    }
  free(envp);
  return (envp_new);
}

char		*get_env(char *name, char **envp)
{
  int		j;
  int		len;
  int		cmp;

  j = 0;
  len = custom_len(envp[j], '=');
  while (envp[j] != NULL)
    {
      cmp = my_strncmp(name, envp[j], len - 1);
      if (cmp == 0)
	{
	  return (my_strdup(envp[j] + len + 1));
	}
      else
	{
	  j++;
	  len = custom_len(envp[j], '=');
	}
    }
  return (NULL);
}
