/*
** my_str_to_word_tab.c for minishell1 in /home/tahery_b/rendu/2016/PSU/PSU_2016_minishell1/src
** 
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
** 
** Started on  Sat Jan 21 00:28:21 2017 Tahery Alexandre
** Last update Wed Mar  1 19:05:08 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include "my_strtowordtab.h"

static int	is_step(const char c, const char *step)
{
  int		count;

  count = 0;
  while (step[count] != '\0')
    {
      if (step[count] == c)
	return (0);
      count += 1;
    }
  return (1);
}

static int	count_word(const char *str, const char *step)
{
  int		count;
  int		i;

  i = 0;
  while (is_step(str[i], step) == 0)
    i++;
  if (str[i] == '\0')
    return (0);
  count = 1;
  while (str[i] != '\0')
    {
      if (is_step(str[i], step) == 0)
	{
	  while (is_step(str[i + 1], step) == 0 && str[i + 1] != '\0')
	    i++;
	  if (is_step(str[i + 1], step) != 0 && str[i + 1] != '\0')
	    count += 1;
	}
      i++;
    }
  return (count);
}

static char	**next_str_to_wordtab(char **tab, const char *str,
				      const char *step, t_strtab *data)
{
  while (str[data->i] != '\0')
    {
      if (is_step(str[data->i], step) == 0)
  	{
  	  while (is_step(str[data->i + 1], step) == 0 &&
		 str[data->i + 1] != '\0')
  	    data->i++;
  	  if (is_step(str[data->i + 1], step) != 0 &&
	      str[data->i + 1] != '\0')
  	    {
	      tab[data->count][data->count2] = '\0';
  	      data->count += 1;
  	      data->count2 = 0;
	      if ((tab[data->count] = malloc(sizeof(char) *
					    (my_strlen(str) + 1))) == NULL)
		return (NULL);
  	    }
  	}
      else
	tab[data->count][data->count2++] = str[data->i];
      data->i++;
    }
  tab[data->count][data->count2] = '\0';
  return (tab);
}

char		**my_str_to_wordtab(const char *str, const char *step)
{
  char		**tab;
  t_strtab	data;

  if (str == NULL || my_strlen(str) == 0 ||
      (data.wrd = count_word(str, step)) == 0 ||
      (tab = malloc(sizeof(char *) * (data.wrd + 1))) == NULL)
    return (NULL);
  tab[data.wrd] = NULL;
  data.i = 0;
  while (is_step(str[data.i], step) == 0)
    data.i++;
  if (str[data.i] == '\0')
    return (0);
  data.count = 0;
  data.count2 = 0;
  if ((tab[data.count] = malloc(sizeof(char *) *
				(my_strlen(str) + 1))) == NULL)
    return (NULL);
  tab = next_str_to_wordtab(tab, str, step, &data);
  return (tab);
}
