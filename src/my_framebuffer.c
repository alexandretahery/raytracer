/*
** my_framebuffer.c for bsraytracer1 in /home/alexandre/rendu/2016/Graphic/bsraytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Feb 10 15:09:33 2017 Alexandre Tahery
** Last update Sun Mar 19 12:24:11 2017 Alexandre Tahery
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*array;
  int			count;

  count = 0;
  if ((array = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  array->width = width;
  array->height = height;
  if ((array->pixels = malloc((sizeof(sfUint8) *
			       (width * height)) * 4)) == NULL)
    return (NULL);
  while (count != ((width * height) * 4))
    {
      array->pixels[count] = 0;
      count += 1;
    }
  return (array);
}

void my_framebuffer_destroy(t_my_framebuffer *array)
{
  free(array);
}
