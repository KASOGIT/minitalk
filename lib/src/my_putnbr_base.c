/*
** my_putnbr_base.c for my_putnbr_base.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 09:51:33 2014 adam kaso
** Last update Fri Dec  5 14:49:01 2014 Kaso Soto
*/

#include "my.h"

void	my_putnbr_base(int nbr, char *base)
{
  int	result;
  int	div;
  int	size_base;

  div = 1;
  size_base = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  while (nbr / div >= size_base)
    div *= size_base;
  while (div > 0)
    {
      result = (nbr / div) % size_base;
      my_putchar(base[result]);
      div /= size_base;
    }
}
