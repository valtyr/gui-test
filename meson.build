project('gui', 'cpp', default_options : ['c_std=c11', 'cpp_std=c++11'])

sdl = dependency('sdl2')
sdlttf = dependency('SDL2_ttf')

src = [
  'src/main.cpp',
  'src/loop.cpp',
  'src/renderer.cpp',
]

executable('gui', src, dependencies : [sdl, sdlttf])