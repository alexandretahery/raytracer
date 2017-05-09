/*
** framebuffer.h for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Mar  8 17:08:27 2017 Alexandre Tahery
** Last update Thu Mar 16 14:20:14 2017 Alexandre Tahery
*/

#ifndef FRAMEBUFFER_H_
# define FRAMEBUFFER_H_

# define SCREEN_WIDTH 400
# define SCREEN_HEIGHT 300

# include <SFML/Graphics.h>

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_framebuffer_destroy(t_my_framebuffer *array);
void			my_put_pixel(t_my_framebuffer *framebuffer, int x,
				     int y, sfColor color);

#endif /* !FRAMEBUFFER_H_ */
