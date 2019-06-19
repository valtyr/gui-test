#include "loop.h"

void Loop::startLoop(LoopCallbackFunction update, LoopCallbackFunction render)
{
  SDL_Event e;
  while (1)
  {
    auto start = std::chrono::high_resolution_clock::now();

    // Event polling
    if (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN)
        break;
    }

    // Call logic
    if (update != nullptr)
      update();
    if (render != nullptr)
      render();

    auto end = std::chrono::high_resolution_clock::now();
    int processing_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    int delay = (1000 / FRAMERATE) - processing_time;
    SDL_Delay(delay > 0 ? delay : 0);
  }
}