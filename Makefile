##
## Makefile for raytracer1 in /home/alexandre/rendu/2016/Graphic/raytracer1
## 
## Made by Alexandre Tahery
## Login   <alexandre1.tahery@epitech.eu>
## 
## Started on  Tue Feb 14 17:40:59 2017 Alexandre Tahery
## Last update Wed Mar  8 16:04:44 2017 Alexandre Tahery
##

NAME	= raytacer1

SRC	= src/main.c \
	  src/sphere.c \
	  src/plane.c \
	  src/my_fonc_pix.c \
	  src/my_framebuffer.c \
	  src/calc_dir_vector.c \
	  src/raytrace_scene.c \
	  src/get_next_line.c \
	  src/set_input.c \
	  src/my_fonc.c \
	  src/my_str_to_word_tab.c \
	  src/color.c \
	  src/color2.c \
	  src/interpretor_intersect.c \
	  src/secu_file.c \
	  src/utils.c \
	  src/cylinder.c \
	  src/cone.c \
	  src/translate.c \
	  src/key_translation.c

OBJ	=$(SRC:.c=.o)

ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif

CFLAGS	+= -W -Wall -Wextra -I./include -lc_graph_prog -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
