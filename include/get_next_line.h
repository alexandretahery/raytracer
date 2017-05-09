/*
** get_next_line.h for wireframe in /home/tahery_b/rendu/2015/CPE/CPE_2015_getnextline
** 
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
** 
** Started on  Tue Dec  6 13:58:35 2016 Tahery Alexandre
** Last update Tue Dec  6 16:56:52 2016 Tahery Alexandre
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_

#ifndef READ_SIZE
# define READ_SIZE (10)
#endif /* !READ_SIZE */

typedef struct		s_stat
{
  char			buf[READ_SIZE + 1];
  int			ret_read;
  int			begin;
}			t_stat;

typedef struct		s_data
{
  char			*str;
  int			count;
}			t_data;

char			*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
