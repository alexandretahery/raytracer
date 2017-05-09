/*
** sphere.c for ratraycer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Tue Feb 28 16:48:09 2017 Alexandre Tahery
** Last update Thu Mar 16 15:25:51 2017 Alexandre Tahery
*/
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "raytracing.h"

float			intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
					 float radius)
{
  float			a;
  float			b;
  float			c;
  float			delta;
  float			result;

  a = (dir_vector.x) * (dir_vector.x) + (dir_vector.y) * (dir_vector.y)
    + (dir_vector.z) * (dir_vector.z);
  b = 2 * ((eye_pos.x * (dir_vector.x)) + (eye_pos.y) *
	   (dir_vector.y) + (eye_pos.z) * (dir_vector.z));
  c = (eye_pos.x * eye_pos.x) + (eye_pos.y * eye_pos.y)
    + (eye_pos.z * eye_pos.z) - (radius * radius);
  delta = (b * b) - (4 * a * c);
  if (delta > 0.0f)
    result = delta_2s(delta, a, b);
  else if (delta == 0.0f)
    {
      if (a == 0.0f)
	return (-1);
      result = - b / (2 * a);
    }
  else
    result = -1;
  return (result);
}
