#include "renderer.h"

int Renderer::initialize()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }
  TTF_Init();
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);

  window = SDL_CreateWindow(
      "Hey presto",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_ALLOW_HIGHDPI);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_RenderSetScale(renderer, SCALE_FACTOR, SCALE_FACTOR);

  if (!(bodyFont = TTF_OpenFont("../fonts/trenco.ttf", 16)))
  {
    printf("%s\n", TTF_GetError());
    return 0;
  }

  if (!(headerFont = TTF_OpenFont("../fonts/early57.ttf", 15)))
  {
    printf("%s\n", TTF_GetError());
    return 0;
  }

  return 1;
}

void Renderer::teardown()
{
  TTF_CloseFont(bodyFont);
  TTF_CloseFont(headerFont);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Renderer::renderFrame()
{
  SDL_RenderClear(renderer);
  setHeader("LP filter");
  SDL_RenderPresent(renderer);
}

void Renderer::blitText(char *text, TTF_Font *font, int x, int y)
{
  SDL_Color white = {255, 255, 255};

  SDL_Surface *textSurface;
  if (!(textSurface = TTF_RenderUTF8_Solid(font, text, white)))
  {
    printf("%s\n", TTF_GetError());
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);

  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstRect = {x, y, texW, texH};

  SDL_RenderCopy(renderer, texture, NULL, &dstRect);

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(textSurface);
}

void Renderer::setHeader(char *header)
{
  blitText(header, headerFont, 3, -1);
}
