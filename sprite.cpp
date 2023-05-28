#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>
#include<sprite.hpp>

Sprite::Sprite(Spritesheet* sheet) {
  m_sheet = sheet;
  m_current_tex = 0;
}

void Sprite::setTexture(Uint32 index) {
  m_current_tex = index;
}

void Sprite::render(SDL_Surface* dest) {
  m_sheet->fromIndex(m_current_tex)->SDLBlitTo(
    dest, m_pos_x, m_pos_y
  );
}