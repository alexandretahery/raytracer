/*
** calc_dir_vector.c for bsraytracer1 in /home/alexandre/rendu/2016/Graphic/bsraytracer1/src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Feb 10 16:07:05 2017 Alexandre Tahery
** Last update Tue Mar  7 17:32:18 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "raytracing.h"
#include "framebuffer.h"

sfVector3f		calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
			   sfVector2i screen_pos)
{
  sfVector3f		vector;

  vector.x = dist_to_plane;
  vector.y = (screen_size.x/2) - screen_pos.x;
  vector.z = (screen_size.y/2) - screen_pos.y;
  return (vector);
}
