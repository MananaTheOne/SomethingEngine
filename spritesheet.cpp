#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>


Spritesheet::Spritesheet(ISurface* sheet) {
  m_sheet = sheet;
}

Spritesheet::~Spritesheet() { 
  m_sheet->~ISurface();
}

SDL_Surface* Spritesheet::fromRect(SDL_Rect rect) {
  SDL_Surface* surf = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
  m_sheet->SDLBlitTo(surf, -rect.x, -rect.y);
  return surf;
}

void Spritesheet::appendSprites(SDL_Rect rect[], int id[]) {
  int len = sizeof(id)/sizeof(int);
  SDL_Surface* m_sprites[len];

  for (int i=0; i<len; i++) {
    m_sprites[i] = fromRect(rect[i]);
  }
}