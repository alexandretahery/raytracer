/*
** raycasting.h for raycasting in /home/alexandre/rendu/2016/Graphic/raytracer1/src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Tue Feb 14 17:54:23 2017 Alexandre Tahery
** Last update Thu Mar 16 14:16:04 2017 Alexandre Tahery
*/

#ifndef RAYCASTING_H_
# define RAYCASTING_H_

#include "framebuffer.h"
# define FAIL 1
# define SUCCESS 0
# define CONTINUE 0
# define END -1
# define DIST_SCREEN 500
# define INPUT_STR 0
# define INPUT_X 1
# define INPUT_Y 2
# define INPUT_Z 3
# define INPUT_R 4
# define INPUT_COLOR 5
# define BLACK "black"
# define WHITE "white"
# define RED "red"
# define GREEN "green"
# define BLUE "blue"
# define YELLOW "yellow"
# define MAGENTA "magenta"
# define CYAN "cyan"

typedef struct		s_sf
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*buffer_pix;
  sfEvent		event;
}			t_sf;

typedef struct	s_array
{
  int		size;
  int		**array_int;
}		t_array;

typedef struct	s_screen
{
  sfVector2i	screen_pos;
  sfVector2i	screen_size;
}		t_screen;

typedef struct	s_obj
{
  char		*str;
  sfVector3f	obj_pos;
  sfColor	color;
  float		radius;
  float		k;
}		t_obj;

float			delta_2s(float delta, float a, float b);
void			my_put_pixel(t_my_framebuffer *framebuffer, int x,
				     int y, sfColor color);
int			process_game_loop(sfRenderWindow *window, sfSprite *sprite);
sfVector3f		calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
					  sfVector2i screen_pos);
float			intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
					 float radius);
float			intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float			intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
					   float semiangle);
float			intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
				       float semiangle);
void			raytrace_scene(t_my_framebuffer *framebuffer, t_obj **obj,
				       sfVector3f *input_key);
void			init_sfVector3f(sfVector3f *init, int x, int y, int z);
t_obj			**set_obj(char *file);
int			my_getnbr(char *str);
int			my_strlen(const char *str);
int			my_strcmp(char *str1, char *str2);
sfColor			black(void);
sfColor			white(void);
sfColor			red(void);
sfColor			green(void);
sfColor			blue(void);
sfColor			yellow(void);
sfColor			magenta(void);
sfColor			cyan(void);
void			interpretor_intersect(t_screen screen, t_obj **obj_array,
					      t_my_framebuffer *framebuffer,
					      sfVector3f *input_key);
int			choose_test(char *str);
int			secu_file(char **array);
void			key_translation(sfVector3f *eye_pos);
sfVector3f		translate(sfVector3f to_translate,
				  sfVector3f translation);

#endif /* !RAYCASTING_H_ */
