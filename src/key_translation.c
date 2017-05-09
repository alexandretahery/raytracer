/*
** key_translation.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Tue Mar  7 17:26:02 2017 Alexandre Tahery
** Last update Tue Mar  7 21:03:13 2017 Alexandre Tahery
*/

#include <SFML/Graphics.h>
#include "raytracing.h"

void		x_key(sfVector3f *eye_pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    eye_pos->x -= 1;
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    eye_pos->x += 1;
}

void		y_key(sfVector3f *eye_pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    eye_pos->y -= 1;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    eye_pos->y += 1;
}

void		z_key(sfVector3f *eye_pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
    eye_pos->z += 1;
  if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue)
    eye_pos->z -= 1;
}

void		key_translation(sfVector3f *eye_pos)
{
  x_key(eye_pos);
  y_key(eye_pos);
  z_key(eye_pos);
}
