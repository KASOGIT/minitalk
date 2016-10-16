/*
** client.c for client in /home/soto_a/rendu/PSU_2014_minitalk
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 16 17:35:21 2015 KASO soto
** Last update Sat Mar 21 13:02:09 2015 KASO soto
*/

#include "client.h"

t_data	g_data;

void	my_usage()
{
  my_putstr("Usage: ./client + pid_serv + \"data\"");
}

void		send_data(int type)
{
  static int	pos_str = 0;
  static int	a = sizeof(char) * 8 - 1;

  if (type == 12)
    exit(EXIT_SUCCESS);
  if ((g_data.str[pos_str] >> a) & 1)
    kill(g_data.pid, SIGUSR1);
  else
    kill(g_data.pid, SIGUSR2);
  if (a == 0)
    {
      pos_str++;
      a = 7;
    }
  else
    a--;
}

void	send_size_to_serv(int size_str)
{
  int	i;

  i = (sizeof(int) * 8 - 1);
  while (i > -1)
    {
      usleep(50);
      if ((size_str >> i) & 1)
	kill(g_data.pid, SIGUSR1);
      else
	kill(g_data.pid, SIGUSR2);
      usleep(50);
      i--;
    }
}

void	send_pid_to_serv()
{
  int	i;
  pid_t	pid;

  i = (sizeof(pid_t) * 8 - 1);
  pid = getpid();
  while (i > -1)
    {
      usleep(50);
      if ((pid >> i) & 1)
	kill(g_data.pid, SIGUSR1);
      else
	kill(g_data.pid, SIGUSR2);
      usleep(50);
      i--;
    }
}

int	main(int ac, char **av)
{
  signal(SIGUSR1, &send_data);
  signal(SIGUSR2, &send_data);
  if (ac == 3)
    {
      g_data.str = av[2];
      g_data.pid = (pid_t)my_getnbr(av[1]);
      send_pid_to_serv();
      send_size_to_serv(my_strlen(g_data.str));
      while (pause());
    }
  else
    my_usage();
  return (0);
}
