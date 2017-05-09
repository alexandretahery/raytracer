/*
** utils.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Mar  3 13:31:42 2017 Alexandre Tahery
** Last update Sun Mar 19 12:22:06 2017 Alexandre Tahery
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "raytracing.h"

float			delta_2s(float delta, float a, float b)
{
  float			result1;
  float			result2;
  float			ret;

  if (a == 0.0f)
    return (-1);
  result1 = (- b + sqrtf(delta)) / (2 * a);
  result2 = (- b - sqrtf(delta)) / (2 * a);
  if (result1 < 0 && result2)
    return (-1);
  if (result1 > result2)
    {
      ret = result2;
      if (ret < 0)
	return (result1);
      return (ret);
    }
  else
    {
      ret = result1;
      if (ret < 0)
	return (result2);
      return (ret);
    }
  return (ret);
}
