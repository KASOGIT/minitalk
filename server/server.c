/*
** serveur.c for serveur in /home/soto_a/rendu/PSU_2014_minitalk
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 16 17:34:59 2015 KASO soto
** Last update Sat Mar 21 13:07:50 2015 KASO soto
*/

#include "server.h"

void	get_pid_client(int type, int *pid, int *count, int *get_pid)
{
  if (type == 10)
    {
      (*pid) <<= 1;
      (*pid)++;
    }
  else if (type == 12)
    (*pid) <<= 1;
  (*count)++;
  if ((*count) == (sizeof(pid_t) * 8))
    {
      (*get_pid) = 1;
      (*count) = 0;
    }
}

int	get_size_str(int type, int *size_str, int *count, int *get_size)
{
  if (type == 10)
    {
      (*size_str) <<= 1;
      (*size_str)++;
    }
  else if (type == 12)
    (*size_str) <<= 1;
  (*count)++;
  if ((*count) == (sizeof(int) * 8))
    {
      (*get_size) = 1;
      (*count) = 0;
      return (1);
    }
  return (-1);
}

void	get_char_bit(int type, char *c, int *count, int *check_size)
{
  if (type == 10)
    {
      (*c) <<= 1;
      (*c)++;
    }
  else if (type == 12)
    (*c) <<= 1;
  (*count)++;
  if ((*count) == (sizeof(char) * 8) && (*c) != '\0')
    {
      (*check_size)++;
      my_putchar((*c));
      (*count) = 0;
    }
}

void		add_data(int type)
{
  static int	size_str = 0;
  static int	get_pid = 0;
  static int	get_size = 0;
  static int	check_size = 0;
  static pid_t	pid = 0;
  static char	c = 0;
  static int	count = 0;

  if (get_pid == 0)
    get_pid_client(type, &pid, &count, &get_pid);
  else if (get_pid && get_size == 0)
    {
      if (get_size_str(type, &size_str, &count, &get_size) != -1)
	kill(pid, SIGUSR1);
    }
  else
    {
      get_char_bit(type, &c, &count, &check_size);
      if (check_size == size_str
	  && reset_info_var(&get_pid, &get_size, &count))
	kill(reset_data_var(&size_str, &pid, &c, &check_size), SIGUSR2);
      if (get_pid)
	kill(pid, SIGUSR1);
    }
}

int	main()
{
  signal(SIGUSR1, &add_data);
  signal(SIGUSR2, &add_data);
  display_pid();
  while (pause());
  return (0);
}
