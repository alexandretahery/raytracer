/*
** translate.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Tue Mar  7 17:18:54 2017 Alexandre Tahery
** Last update Tue Mar  7 19:27:11 2017 Alexandre Tahery
*/

#include <SFML/Graphics.h>

sfVector3f		translate(sfVector3f to_translate,
				  sfVector3f translation)
{
  to_translate.x += translation.x;
  to_translate.y += translation.y;
  to_translate.z += translation.z;
  return (to_translate);
}
