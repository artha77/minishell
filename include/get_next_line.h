/*
** get_next_line.h for get_next_line in /home/artha/CPE_2016_getnextline/src
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Thu Jan 12 13:22:18 2017 dylan renard
** Last update Sat Jan 14 15:25:08 2017 dylan renard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define READ_SIZE	40000
# define FD		statique->fd != fd

typedef struct		s_stat
{
  char			*rest;
  int			fd;
}			t_stat;

char			*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
