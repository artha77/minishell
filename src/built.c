/*
** built.c for mysh in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 14:58:03 2017 dylan renard
** Last update Sun Jan 22 17:00:18 2017 dylan renard
*/

#include "shell.h"

int		cd(char *path)
{
  int		ret;

  ret = chdir(path);
  if (ret == -1)
    perror("error ");
  return (ret);
}

int		len_env(char **envp)
{
  int		i;

  i = 0;
  if (envp == NULL)
    return (0);
  while (envp[i] != NULL)
    i++;
  return (i);
}

char		**set_env(char *name, char *value, char **envp)
{
  char		**envp_new;
  int		len;
  int		i;
  int		pos;

  i = 0;
  pos = env_pos(name, envp);
  if (pos == -1)
    {
      len = len_env(envp);
      if ((envp_new = malloc((len + 2) * sizeof(char *))) == NULL) exit(84);
      envp_new[len + 1] = NULL;
      while (envp[i] != NULL)
	{
	  envp_new[i] = my_strdup(envp[i]);
	  i++;
	}
      envp_new[i] = my_strcat(name, "=");
      envp_new[i] = my_strcat(envp_new[i], value);
      free(envp);
      return (envp_new);
    }
  envp[pos] = my_strcat(name, "=");
  envp[pos] = my_strcat(envp[pos], value);
  return (envp);
}

int		xexecve(char *command, char **av, char **envp)
{
  pid_t		pid;
  int		statut;

  pid = fork();

  if (pid == -1)
    {
      my_puts_fd("failed to fork", 2);
    }
  else if (pid > 0)
    {
      waitpid(pid, &statut, 0);
    }
  else
    {
      if (execve(command, av, envp))
	perror("error ");
      exit(0);
    }
}

int		custom_len(char *str, char delim)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != delim && str[i] != '\0')
    i++;
  return (i);
}
