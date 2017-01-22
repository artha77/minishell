/*
** shell.h for mysh in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 15:03:22 2017 dylan renard
** Last update Sun Jan 22 20:08:02 2017 dylan renard
*/

#ifndef SHELL_H_
# define SHELL_H_
#include "my.h"
#include "gnl.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int		cd(char *path);
char		**set_env(char *name, char *value, char **envp);
int		xexecve(char *command, char **av, char **envp);
int		custom_len(char *str, char delim);
void		display_env(char **envp);
int		env_pos(char *name, char **envp);
char		**unset_env(char *name, char **envp);
char		*get_env(char *name, char **envp);
int		my_strncmp(char *s1, char *s2, int n);
int		len_env(char **envp);
char		**x_env(char **av, char **envp);
char		**x_setenv(char **av, char **envp);
char		**x_unsetenv(char **av, char **envp);
char		**x_cd(char **av, char **envp);
char		**x_exit(char **av, char **envp);
char		*find_name(char *str);
char		*find_value(char *str);

#endif /* !SHELL_H_ */
