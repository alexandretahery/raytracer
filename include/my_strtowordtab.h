/*
** my_strtowordtab.h for minishell1 in /home/tahery_b
** 
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
** 
** Started on  Sat Jan 21 00:30:14 2017 Tahery Alexandre
** Last update Wed Mar  1 22:24:34 2017 Alexandre Tahery
*/

#ifndef MY_STRTOWORDTAB_H_
# define MY_STRTOWORDTAB_H_

#include "raytracing.h"

typedef struct s_strtab
{
  int		wrd;
  int		i;
  int		count;
  int		count2;
}		t_strtab;

char		**my_str_to_wordtab(const char *str, const char *step);

#endif /* !MY_STRTOWORDTAB_H_ */
