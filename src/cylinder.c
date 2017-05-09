/*
** cylinder.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Mar  3 13:01:04 2017 Alexandre Tahery
** Last update Thu Mar 16 15:17:12 2017 Alexandre Tahery
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "raytracing.h"

float			intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius)
{
  float			a;
  float			b;
  float			c;
  float			delta;
  float			result;

  a = (dir_vector.x * dir_vector.x) + (dir_vector.y * dir_vector.y);
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y));
  c = (eye_pos.x * eye_pos.x) + (eye_pos.y * eye_pos.y)
    - (radius * radius);
  if (a == 0)
    return (-1);
  delta = (b * b) - (4 * a * c);
  if (delta > 0.0f)
    result = delta_2s(delta, a, b);
  else if (delta == 0.0f)
    result = - b / (2 * a);
  else
    result = -1;
  return (result);
}
