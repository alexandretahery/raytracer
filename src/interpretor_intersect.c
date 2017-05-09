/*
** interpretor_intersect.c for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Thu Mar  2 00:49:10 2017 Alexandre Tahery
** Last update Mon Mar 13 17:05:44 2017 Alexandre Tahery
*/

#include <SFML/Graphics.h>
#include "raytracing.h"
#include "framebuffer.h"

static float	(*ptrintersect[5])(sfVector3f eyes_pos, sfVector3f dir_vector,
				   float info) =
{
  intersect_sphere,
  intersect_cylinder,
  intersect_cone,
  NULL
};

int			choose_test(char *str)
{
  char			*array[6];
  int			count;

  count = 0;
  array[0] = "plane";
  array[1] = "sphere";
  array[2] = "cylinder";
  array[3] = "cone";
  array[5] = NULL;

  while (array[count] != NULL)
    {
      if (my_strcmp(array[count], str) == SUCCESS)
	return (count);
      count += 1;
    }
  return (-1);
}

void			return_delta(t_obj *obj, t_screen screen, int ret)
{
  sfVector3f		eye_pos;
  sfVector3f		dir_vector;

  dir_vector = calc_dir_vector(DIST_SCREEN, screen.screen_size,
			       screen.screen_pos);
  init_sfVector3f(&eye_pos, obj->obj_pos.x,
		  obj->obj_pos.y, obj->obj_pos.z);
  if (ret == 0)
    obj->k = intersect_plane(eye_pos, dir_vector);
  else
    {
      init_sfVector3f(&eye_pos, obj->obj_pos.x,
		      obj->obj_pos.y, obj->obj_pos.z);
      obj->k = ptrintersect[ret - 1](eye_pos, dir_vector,
						  obj->radius);
    }
}

void			interpretor_intersect(t_screen screen, t_obj **obj_array,
					      t_my_framebuffer *framebuffer,
					      sfVector3f *input_key)
{
  int			ret;
  int			count;
  float			old_k;
  sfColor		color;

  count = 0;
  old_k = -1;
  color = sfBlack;
  while (obj_array[count] != NULL)
    {
      ret = choose_test(obj_array[count]->str);
      return_delta(obj_array[count], screen, ret);
      if (obj_array[count]->k > 0.0f &&
	  (obj_array[count]->k < old_k || old_k < 0.0f))
	{
	  old_k = obj_array[count]->k;
	  color = obj_array[count]->color;
	}
      obj_array[count]->obj_pos =
	translate(obj_array[count]->obj_pos, *input_key);
      count += 1;
    }
  my_put_pixel(framebuffer, screen.screen_pos.x, screen.screen_pos.y, color);
  init_sfVector3f(input_key, 0, 0, 0);
}
