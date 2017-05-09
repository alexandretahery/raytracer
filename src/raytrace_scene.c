/*
** raytrace_scene.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Mar  1 15:52:28 2017 Alexandre Tahery
** Last update Wed Mar  8 17:13:21 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "raytracing.h"
#include "framebuffer.h"

void			init_sfVector3f(sfVector3f *init, int x, int y, int z)
{
  init->x = x;
  init->y = y;
  init->z = z;
}

void			init_sfVector2i(sfVector2i *init, int x, int y)
{
  init->x = x;
  init->y = y;
}

void			raytrace_scene(t_my_framebuffer *framebuffer, t_obj **obj,
				       sfVector3f *input_key)
{
  t_screen		screen;

  init_sfVector2i(&screen.screen_size, framebuffer->width,
		  framebuffer->height);
  screen.screen_pos.y = 0;
  while (screen.screen_pos.y != SCREEN_HEIGHT)
    {
      screen.screen_pos.x = 0;
      while (screen.screen_pos.x != SCREEN_WIDTH)
	{
	  interpretor_intersect(screen, obj, framebuffer, input_key);
	  screen.screen_pos.x += 1;
	}
      screen.screen_pos.y += 1;
    }
}
