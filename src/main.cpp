#include "renderer.h"
#include "loop.h"

Renderer renderer;
Loop loop;

void update() {}
void render() { renderer.renderFrame(); }

int main()
{

  renderer.initialize();
  loop.startLoop(update, render);
  renderer.teardown();

  return 0;
}