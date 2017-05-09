#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"

void			my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x >= 0 && y >= 0)
    {
      framebuffer->pixels[(x + framebuffer->width * y) * 4] = color.r;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 1] = color.g;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 2] = color.b;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 3] = color.a;
    }
}
