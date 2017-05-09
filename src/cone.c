/*
** cone.c<src> for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Mar  3 16:53:22 2017 Alexandre Tahery
** Last update Tue Mar 14 17:36:10 2017 Alexandre Tahery
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "raytracing.h"

float			intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
				       float semiangle)
{
  float			a;
  float			b;
  float			c;
  float			r;
  float			delta;
  float			result;

  if (semiangle == 90 || semiangle == 180)
    return (-1);
  r = semiangle * M_PI / 180;
  a = pow(dir_vector.x, 2.0f) + pow(dir_vector.y, 2.0f) -
    (pow(dir_vector.z, 2.0f) * pow(tan(r), 2.0f));
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y)
	   - (eye_pos.z * dir_vector.z * pow(tan(r), 2.0f)));
  c = pow(eye_pos.x, 2.0f) + pow(eye_pos.y, 2.0f)
    - (pow(eye_pos.z, 2.0f) * pow(tan(r), 2.0f));
  delta = (b * b) - (4 * a * c);
  if (delta > 0.0f)
    result = delta_2s(delta, a, b);
  else if (delta == 0.0f)
    result = - b / (2 * a);
  else
    result = -1;
  return (result);
}
