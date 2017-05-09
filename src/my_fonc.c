/*
** my_fonc.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Mar  1 18:52:25 2017 Alexandre Tahery
** Last update Fri Mar 17 01:55:52 2017 Alexandre Tahery
*/

#include	"raytracing.h"

int		my_strlen(const char *str)
{
  int		count;

 count = 0;
 while (str[count] != '\0')
  count += 1;
 return (count);
}

int		my_getnbr(char *str)
{
  int		l;
  int		deci;
  int		result;

  l = (my_strlen(str) - 1);
  deci = 1;
  result = 0;
  while (l >= 0)
    {
      if (str[l] != '-' && str[l] != '+')
	{
	  result = (str[l] - 48) * deci  + result;
	  deci = deci * 10;
	  l--;
	}
      else if (str[l] == '-')
	{
	  l--;
	  result = result * -1;
	}
      else
	l--;
    }
  return (result);
}

int		my_strcmp(char *str1, char *str2)
{
  int		count;

  count = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (FAIL);
  while (str2[count] != '\0' && str1[count] != '\0')
    {
      if (str1[count] != str2[count])
	return (FAIL);
      count += 1;
    }
  return (SUCCESS);
}
