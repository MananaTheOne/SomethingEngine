#pragma once

#include <SDL2/SDL.h>

/**
 * @class ISurface
 * @brief *Improved* Surface
 *
 * The ISurface class represents an improved surface and provides various functionalities
 * for blitting and manipulating surfaces.
 */
class ISurface {
public:
    /**
     * @brief Blit the ISurface onto another ISurface.
     *
     * Blits the source ISurface onto the current ISurface with the specified offsets.
     *
     * @param src The source ISurface to blit from.
     * @param x   The x-axis offset for blitting.
     * @param y   The y-axis offset for blitting.
     */
    void Blit(ISurface* src, int x, int y);

    /**
     * @brief Blit an SDL_Surface onto the ISurface.
     *
     * Blits the source SDL_Surface onto the current ISurface with the specified offsets.
     *
     * @param src The source SDL_Surface to blit from.
     * @param x   The x-axis offset for blitting.
     * @param y   The y-axis offset for blitting.
     */
    void SDLBlit(SDL_Surface* src, int x, int y);

    /**
     * @brief Blit the ISurface onto an SDL_Surface.
     *
     * Blits the ISurface onto the destination SDL_Surface with the specified offsets.
     *
     * @param dest The destination SDL_Surface to blit to.
     * @param x    The x-axis offset for blitting.
     * @param y    The y-axis offset for blitting.
     */
    void SDLBlitTo(SDL_Surface* dest, int x, int y);

    /**
     * @brief Blit the ISurface onto another surface with source and destination rectangles.
     *
     * Performs blitting of the ISurface onto the destination surface using the specified source and destination rectangles.
     *
     * @param dest      The destination surface to blit to.
     * @param src_rect  The source rectangle defining the area to blit from.
     * @param dest_rect The destination rectangle defining the area to blit to.
     */
    void _UpperBlit(SDL_Surface* dest, SDL_Rect* src_rect, SDL_Rect* dest_rect);

    /**
     * @brief ISurface constructor for existing surfaces.
     *
     * Constructs an ISurface object by copying an existing SDL_Surface.
     *
     * @param surf The SDL_Surface to copy from.
     */
    ISurface(SDL_Surface* surf);

    /**
     * @brief ISurface constructor for .bmp images.
     *
     * Constructs an ISurface object from a .bmp image file.
     *
     * @param path The path to the .bmp image file.
     */
    ISurface(const char* path);

    /**
     * @brief ISurface destructor.
     */
    ~ISurface();

private:
    SDL_Surface* m_surf;   /**< Pointer to the SDL_Surface associated with the ISurface. */
    SDL_Rect m_rect;       /**< Rectangle defining the dimensions of the ISurface. */
};
