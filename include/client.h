/*
** minitalk.h for minitalk in /home/soto_a/rendu/PSU_2014_minitalk/include
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 16 17:52:43 2015 KASO soto
** Last update Sat Mar 21 12:47:49 2015 KASO soto
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/types.h>
#include <signal.h>
#include "my.h"

typedef struct	s_data
{
  char		*str;
  pid_t		pid;
}		t_data;

void	my_usage();
void	send_data(int type);
void	send_size_to_serv(int size_str);
void	send_pid_to_serv();

#endif /* !CLIENT_H_ */
