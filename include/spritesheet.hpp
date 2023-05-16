#pragma once

#include<SDL2/SDL.h>
#include<isurface.hpp>

/**
 * Basic spritesheet class.
*/
class Spritesheet {
  public:
    SDL_Surface* fromRect(SDL_Rect rect);
    void appendSprite(SDL_Rect rect, int id);
    Spritesheet(ISurface* sheet);
    ~Spritesheet();
  
  private:
    ISurface* m_sheet;
};