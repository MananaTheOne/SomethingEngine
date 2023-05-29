#include<vector>
#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>
#include<bgtiles.hpp>


Background::Background(Uint32 sc_width, Uint32 sc_height, Spritesheet* sheet) {
  m_sheet = sheet;
  m_sw = sc_width; m_sh = sc_height;
  m_buffer = std::vector<Uint32>();
  m_noffset_y = m_noffset_x = m_offset_x = m_offset_y = 0;
}

void Background::load_map(std::vector<Uint32> data, Uint32 width, Uint32 height) {
  m_buffer = data;
  m_w = width;m_h = height;
}

void Background::change_offset(int x, int y) {
  m_noffset_x = x; m_noffset_y = y;
}

void Background::render(SDL_Surface* dest) {
  const int tileSize = 8;
  const int tilesPerRow = m_sw / tileSize;

  int px, py;
  for (std::size_t i = 0; i < m_buffer.size(); ++i) {
      py = static_cast<int>(i) % tilesPerRow;
      px = static_cast<int>(i) / tilesPerRow;
      m_sheet->fromIndex(m_buffer[i])->SDLBlitTo(dest, px * tileSize, py * tileSize);
  }
}