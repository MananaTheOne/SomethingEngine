// #include<spritesheet.hpp>
#include<isurface.hpp>
#include<SDL2/SDL.h>
#include<iostream>


SDL_Window* window;
SDL_Surface* winSurf;

int init() {
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
    std::cout << "SDL2 cannot be initialized.. Error:" << SDL_GetError() << "\n"; return -1; }
  window = SDL_CreateWindow("Phobos ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    256, 192, 0
  ); if ( !window ) {
    std::cout << "Window cannot be created.. Error:" << SDL_GetError() << "\n"; return -1; 
  } winSurf = SDL_GetWindowSurface(window);

  return 0;
}

void quit() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(int argc, char* argv[]) {
  SDL_Event ev;

  init();

  ISurface test("nicetexture.bmp");

  bool run = true;
  while (run) {
    while (SDL_PollEvent(&ev)) {
      switch (ev.type) {
        case SDL_QUIT:
          run = false;
          break;
        
        default:
          break;
      }
    }
    SDL_FillRect(winSurf, NULL, 0xffffffff);
    test.SDLBlitTo(winSurf, 0, 0);
    SDL_UpdateWindowSurface(window);
  }

  quit();
  return 0;
}