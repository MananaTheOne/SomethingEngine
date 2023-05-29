#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <isurface.hpp>
#include <spritesheet.hpp>

/**
 * @class Background
 * @brief Background tile system.
 *
 * The Background class represents a tile-based background system. It is responsible for loading and rendering
 * background tiles using a provided spritesheet.
 */
class Background {
public:
    /**
     * @brief Background constructor.
     *
     * @param sc_width  Width of the screen.
     * @param sc_height Height of the screen.
     * @param sheet     Pointer to the Spritesheet to be used for rendering the tilemap.
     */
    Background(Uint32 sc_width, Uint32 sc_height, Spritesheet* sheet);

    /**
     * @brief Load the tilemap data.
     *
     * Loads the tilemap data into the background.
     *
     * @param data The vector containing the tilemap data.
     */
    void load_map(std::vector<Uint32> data, Uint32 width, Uint32 height);

    /**
     * @brief Change the offset of the background.
     *
     * Changes the offset of the background by the given values.
     *
     * @param x The new X offset.
     * @param y The new Y offset.
     */
    void change_offset(int x, int y);

    /**
     * @brief Render the background to a surface.
     *
     * Renders the background to the specified SDL_Surface destination.
     *
     * @param dest The destination SDL_Surface to render the background onto.
     */
    void render(SDL_Surface* dest);

private:
    Uint32 m_w;                      /**< Width of the tilemap. */
    Uint32 m_h;                      /**< Height of the tilemap. */
    Uint32 m_sw;                     /**< Width of the screen. */
    Uint32 m_sh;                     /**< Height of the screen. */
    Spritesheet* m_sheet;            /**< Pointer to the Spritesheet used for rendering. */
    std::vector<Uint32> m_buffer;    /**< Buffer containing the tilemap data. */
    int m_noffset_y;                 /**< Normalized Y offset. */
    int m_noffset_x;                 /**< Normalized X offset. */
    int m_offset_x;                  /**< Current X offset. */
    int m_offset_y;                  /**< Current Y offset. */
};