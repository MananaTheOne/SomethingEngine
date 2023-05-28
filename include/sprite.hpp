#pragma once

#include<SDL2/SDL.h>
#include<isurface.hpp>
#include<spritesheet.hpp>

/**
 * Sprite class
*/
class Sprite {
  public:
    /**
     * Sprite constructor
     * 
     * @param sheet A spritesheet to use for the sprite.
    */
    Sprite(Spritesheet* sheet);

    /**
     * Render sprite to a surface
     * 
     * @param dest Where to render the sprtie to.
    */
    void render(ISurface* dest);

    /**
     * Change the texture index to be used on the sprite.
     * 
     * @param index Index of the texture.
    */
    void setTexture(Uint32 index);

  private:
    Spritesheet* m_sheet;
    Uint32 m_current_tex;
    float m_pos_x, m_pos_y;
};