#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 128;
const int SCALE_FACTOR = 4;

class Renderer
{
  SDL_Renderer *renderer;
  SDL_Window *window;
  TTF_Font *bodyFont;
  TTF_Font *headerFont;

public:
  int initialize();
  void teardown();
  void renderFrame();
  void blitText(char *, TTF_Font *, int, int);
  void setHeader(char *);
};
