#include<sprite.hpp>
#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>

Sprite::Sprite(Spritesheet* sheet) {
  m_sheet = sheet;
}

Sprite::render(ISurface* dest) {
  
}