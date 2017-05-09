/*
** main.c for wireframe in /home/tahery_b/rendu/2016/Graphic/wireframe
** 
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
** 
** Started on  Tue Dec  6 12:30:07 2016 Tahery Alexandre
** Last update Wed Mar  8 17:10:14 2017 Alexandre Tahery
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include "raytracing.h"

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow		*window;
  sfVideoMode			mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  if ((window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL))
      == NULL)
    return (NULL);
  return (window);
}

int			display_func(t_sf *sf, t_obj **obj_file, sfVector3f *input_key)
{
  while (sfRenderWindow_isOpen(sf->window))
    {
      key_translation(input_key);
      raytrace_scene(sf->buffer_pix, obj_file, input_key);
      sfSprite_setTexture(sf->sprite, sf->texture, sfTrue);
      sfTexture_updateFromPixels(sf->texture, sf->buffer_pix->pixels,
				 SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      sfRenderWindow_clear(sf->window, sfBlack);
      sfRenderWindow_drawSprite(sf->window, sf->sprite, NULL);
      sfRenderWindow_display(sf->window);
      while (sfRenderWindow_pollEvent(sf->window, &(sf->event)))
  	{
  	  if ((sf->event.type) == sfEvtClosed ||
	      ((sf->event.type) == sfEvtKeyPressed &&
	       (sf->event.key.code) == sfKeyEscape))
  	    {
  	      sfRenderWindow_close(sf->window);
	      return (END);
  	    }
  	}
    }
  sfRenderWindow_destroy(sf->window);
  return (CONTINUE);
}

int			main(int argc, char **argv)
{
  t_sf			sf;
  sfVector3f		input_key;
  t_obj			**obj_file;

  obj_file = NULL;
  init_sfVector3f(&input_key, 0, 0, 0);
  if (argc == 1)
    return (1);
  if ((sf.window = create_window("raytracer1", SCREEN_WIDTH,
				 SCREEN_HEIGHT)) == NULL
      || (sf.sprite = sfSprite_create()) == NULL
      || (sf.texture = sfTexture_create(SCREEN_WIDTH,
					SCREEN_HEIGHT)) == NULL
      || (sf.buffer_pix = my_framebuffer_create(SCREEN_WIDTH,
						SCREEN_HEIGHT)) == NULL)
    return (FAIL);
  if ((obj_file = set_obj(argv[1])) == NULL)
    return (FAIL);
  display_func(&sf, obj_file, &input_key);
  return (SUCCESS);
}
