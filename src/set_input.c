/*
** set_input.c for raytracer in /home/alexandre/rendu/2016/Graphic/raytracer1
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Mar  1 18:03:49 2017 Alexandre Tahery
** Last update Fri Mar 17 01:55:53 2017 Alexandre Tahery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "raytracing.h"
#include "get_next_line.h"
#include "my_strtowordtab.h"

static sfColor	(*ptrcolor[9])() =
{
  black,
  white,
  red,
  green,
  blue,
  yellow,
  magenta,
  cyan,
  NULL
};

sfColor		choose_color(char *str)
{
  char		*token[9];
  int		count;

  count = 0;
  token[0] = BLACK;
  token[1] = WHITE;
  token[2] = RED;
  token[3] = GREEN;
  token[4] = BLUE;
  token[5] = YELLOW;
  token[6] = MAGENTA;
  token[7] = CYAN;
  token[8] = NULL;
  while (token[count] != NULL)
    {
      if (my_strcmp(token[count], str) == SUCCESS)
	  return (ptrcolor[count]());
      count += 1;
    }
  return (sfBlack);
}

int		ret_malloc(char *file)
{
  int		fd;
  int		count;

  count = 0;
  if ((fd = open(file, O_RDONLY)) == FAIL)
    return (-1);
  while ((get_next_line(fd)) != NULL)
    count += 1;
  close(fd);
  return (count);
}

t_obj		**set_obj(char *file)
{
  int		count;
  int		fd;
  char		*str;
  char		**input;
  t_obj		**array_local;

  if (((count = ret_malloc(file)) == -1) || ((fd = open(file, O_RDONLY)) == -1)
      || ((array_local = malloc(sizeof(t_obj *) * (count + 1))) == NULL))
    return (NULL);
  array_local[count] = NULL;
  count = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((array_local[count] = malloc(sizeof(t_obj))) == NULL ||
	  (input = my_str_to_wordtab(str, ":")) == NULL ||
	  secu_file(input) == FAIL)
	return (NULL);
      array_local[count]->str = input[INPUT_STR];
      array_local[count]->obj_pos.x = my_getnbr(input[INPUT_X]);
      array_local[count]->obj_pos.y = my_getnbr(input[INPUT_Y]);
      array_local[count]->obj_pos.z = my_getnbr(input[INPUT_Z]);
      array_local[count]->radius = my_getnbr(input[INPUT_R]);
      array_local[count++]->color = choose_color(input[INPUT_COLOR]);
    }
  return (array_local);
}
