// #include<spritesheet.hpp>
#include<spritesheet.hpp>
#include<isurface.hpp>
#include<sprite.hpp>

#include<SDL2/SDL.h>
#include<iostream>


SDL_Window* window;
SDL_Surface* winSurf;

int init() {
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
    std::cout << "SDL2 cannot be initialized.. Error:" << SDL_GetError() << "\n"; return -1; }
  window = SDL_CreateWindow("Phobos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    256, 192, 0
  ); if ( !window ) {
    std::cout << "Window cannot be created.. Error:" << SDL_GetError() << "\n"; return -1; 
  } 
  winSurf = SDL_GetWindowSurface(window);
  std::cout << "SDL2 initialized successfully.\n";

  return 0;
}

void quit() {
  std::cout << std::endl;
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(int argc, char* argv[]) {
  SDL_Event ev; SDL_Rect emoticon_angryyyy;
  emoticon_angryyyy.x = 0; emoticon_angryyyy.y = 16;
  emoticon_angryyyy.w = 16; emoticon_angryyyy.h = 16;

  std::cout << "Initializing Emote sheet\n";

  Spritesheet emote_sheet("emoticon.bmp");
  emote_sheet.newSprite(emoticon_angryyyy);
  std::cout << "Emote sheet loaded successfully.\n";
  Sprite emoji(&emote_sheet);

  int init_return = init();
  if (init_return < 0) return init_return;

  bool run = true;
  while (run) {
    while (SDL_PollEvent(&ev)) {
      switch (ev.type) {
        case SDL_QUIT:
          run = false;
          break;

        case SDL_MOUSEMOTION:
          emoji.m_pos_x = ev.motion.x;
          emoji.m_pos_y = ev.motion.y;
          break;

        default:
          break;
      }
    }
    SDL_FillRect(winSurf, NULL, 0xffffffff);

    emoji.render(winSurf);

    SDL_UpdateWindowSurface(window);
  }
  quit();
  return 0;
}