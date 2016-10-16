/*
** serveur.h for serveur in /home/soto_a/rendu/PSU_2014_minitalk/include
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 16 18:51:16 2015 KASO soto
** Last update Sat Mar 21 13:30:04 2015 KASO soto
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

void	display_pid();
void	get_pid_client(int type, int *pid, int *count, int *get_pid);
int	get_size_str(int type, int *size_str, int *count, int *get_size);
void	get_char_bit(int type, char *c, int *count, int *check_size);
int	reset_info_var(int *get_pid, int *get_size, int *count);
pid_t	reset_data_var(int *size_str, pid_t *pid, char *c, int *check_size);
void	add_data(int type);

#endif /* !SERVER_H_ */
