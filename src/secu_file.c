/*
** secu_file.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Thu Mar  2 05:54:36 2017 Alexandre Tahery
** Last update Tue Mar  7 17:53:57 2017 Alexandre Tahery
*/

#include "raytracing.h"

int		secu_file(char **array)
{
  int		count;

  count = 0;
  while (array[count] != NULL)
    count += 1;
  if (count != 6)
    return (FAIL);
  if (choose_test(array[INPUT_STR]) == -1)
    return (FAIL);
  return (SUCCESS);
}
