/*
** plane.c for raytracer in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Tue Feb 28 18:51:12 2017 Alexandre Tahery
** Last update Mon Mar 13 17:05:08 2017 Alexandre Tahery
*/

#include <SFML/Graphics.h>

float			intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float			k;

  if (dir_vector.z == 0.0f || eye_pos.z == 0.0f)
    return (-1);
  k = 0;
  k = - 1 * (eye_pos.z / dir_vector.z);
  if (k < 0.0f)
    return (-1);
  return (k);
}
