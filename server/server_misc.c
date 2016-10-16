/*
** server_misc.c for serveur_misc in /home/soto_a/rendu/PSU_2014_minitalk/server
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Mar 20 21:17:30 2015 KASO soto
** Last update Fri Mar 20 21:21:57 2015 KASO soto
*/

#include "server.h"

void	display_pid()
{
  my_put_nbr(getpid());
  my_putchar('\n');
}

int	reset_info_var(int *get_pid, int *get_size, int *count)
{
  (*get_pid) = 0;
  (*get_size) = 0;
  (*count) = 0;
  return (1);
}

pid_t	reset_data_var(int *size_str, pid_t *pid, char *c, int *check_size)
{
  pid_t	tmp_pid;

  tmp_pid = (*pid);
  (*pid) = 0;
  (*c) = 0;
  (*size_str) = 0;
  (*check_size) = 0;
  return (tmp_pid);
}
