#pragma once

#include<SDL2/SDL.h>
#include<isurface.hpp>

/**
 * Basic spritesheet class.
*/
class Spritesheet {
  public:
    /**
     * Literally just crop tool lmao get fucked L
     * 
     * @param rect Rect of the sprite
    */
    SDL_Surface* fromRect(SDL_Rect rect);

    /**
     * Blit directly without saving any Surfaces to memory.
     * 
     * @param rect Rect of the sprite
     * @param dest Where to blit sprite to.
     * @param x    x value of position
     * @param y    y value of position
    */
    void ezBlit(SDL_Rect rect, SDL_Surface* dest, int x, int y);

    /**
     * Spritesheet constructor
     * 
     * @param sheet Pointer of what spritesheet to use
    */
    Spritesheet(ISurface* sheet);

    /**
     * Spritesheet deconstructor
    */
    ~Spritesheet();
  
  private:
    ISurface* m_sheet;
};