#include <stdio.h>
#include <SDL2/SDL.h>
#include <chrono>
#include <functional>

typedef std::function<void()> LoopCallbackFunction;

const int FRAMERATE = 60;

class Loop
{
public:
  void startLoop(LoopCallbackFunction, LoopCallbackFunction);
};