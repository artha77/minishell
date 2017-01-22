/*
** my_strncpy.c for my_strncpy in /home/Artha77/CPool_Day06
** 
** Made by dylan renard
** Login   <Artha77@epitech.net>
** 
** Started on  Mon Oct 10 07:20:13 2016 dylan renard
** Last update Tue Oct 11 17:45:08 2016 dylan renard
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0' && i < n)
    {
      *(dest + i) = *(src + i);
      i = i + 1;
    }
  if (i == n)
    {
      *(dest + i) = '\0';
    }
  return (dest);
}
