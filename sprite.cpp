#include<sprite.hpp>
#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>

Sprite::Sprite(Spritesheet* sheet) {
  m_sheet = sheet;
}

void Sprite::setTexture(Uint32 index) {
  m_current_tex = index;
}

void Sprite::render(ISurface* dest) {
  dest->Blit(
    m_sheet->fromIndex(m_current_tex),
    m_pos_x, m_pos_y
  );
}