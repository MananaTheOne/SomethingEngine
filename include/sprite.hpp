#pragma once

#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>


class Sprite {
  public:
    Sprite(Spritesheet* sheet);
    void render(ISurface* dest);

  private:
    Spritesheet* m_sheet;
    int m_current_tex;
    float m_pos_x, m_pos_y;
};