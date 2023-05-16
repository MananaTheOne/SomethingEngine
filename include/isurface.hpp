#pragma once

#include<SDL2/SDL.h>

/**
 * *Improved* Surface
*/
class ISurface {
  public:
    /**
     * Blit ISurface to ISurface.
     * 
     * @param src The surface to blit from
     * @param x   Offset for the x-axis
     * @param y   Offset for the y-axis
    */
    void Blit(ISurface src, int x, int y);

    /**
     * Blit an SDL_Surface to the ISurface.
     * 
     * @param src The surface to blit from
     * @param x   Offset for the x-axis
     * @param y   Offset for the y-axis
    */
    void SDLBlit(SDL_Surface* src, int x, int y);

    /**
     * Blit ISurface to a SDL_Surface.
     * 
     * @param dest The surface to blit to
     * @param x    Offset for the x-axis
     * @param y    Offset for the y-axis
    */
    void SDLBlitTo(SDL_Surface* dest, int x, int y);

    /**
     * ISurface ctor for already-existing surfaces
     * 
     * @param surf Surface to copy from
    */
    ISurface(SDL_Surface* surf);

    /**
     * ISurface ctor for .bmp images
     * 
     * @param path Path of the BitMap file 
    */
    ISurface(const char* path);

    /**
     * Destructor for ISurface
    */
    ~ISurface();
  
  private:
    SDL_Surface* m_surf;
    SDL_Rect m_rect;
};