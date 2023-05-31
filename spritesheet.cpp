#include<vector>
#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>


Spritesheet::Spritesheet(const char* path) {
  ISurface* surf = new ISurface(path);
  m_sheet = surf;
  m_sprites = std::vector<ISurface>();
}

Spritesheet::Spritesheet(ISurface* sheet) {
  m_sheet = sheet;
  m_sprites = std::vector<ISurface>();
}

Spritesheet::~Spritesheet() { 
  delete m_sheet;
}

ISurface* Spritesheet::fromIndex(Uint32 index) {
  if (index >= m_sprites.size()) return NULL;
  return &m_sprites[index];
}

SDL_Surface* Spritesheet::fromRect(SDL_Rect rect) {
  SDL_Surface* surf = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
  m_sheet->SDLBlitTo(surf, -rect.x, -rect.y);
  return surf;
}

int Spritesheet::newSprite(SDL_Rect rect) {
  m_sprites.emplace_back(fromRect(rect));
  return m_sprites.size() - 1;
}

int Spritesheet::newSprite(SDL_Surface* surf) {
  ISurface isurf(surf);
  m_sprites.emplace_back(isurf);
  return m_sprites.size() - 1;
}

void Spritesheet::ezBlit(SDL_Rect rect, SDL_Surface* dest, int x, int y) {
  SDL_Rect _rect = rect;
    _rect.x = -x; _rect.y = -y;
  m_sheet->_UpperBlit(dest, &rect, &_rect);
}