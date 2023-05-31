#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <isurface.hpp>

/**
 * @class Spritesheet
 * @brief Basic spritesheet class.
 *
 * The Spritesheet class represents a basic spritesheet and provides various functionalities
 * to work with sprites from the spritesheet.
 */
class Spritesheet {
public:
    /**
     * @brief Get the surface of a given area in the spritesheet.
     *
     * @param rect The rectangle defining the area of the sprite in the spritesheet.
     * @return Pointer to the cropped SDL_Surface representing the sprite.
     */
    SDL_Surface* fromRect(SDL_Rect rect);

    /**
     * @brief Get a sprite from the spritesheet by index.
     *
     * @param index The index of the sprite to retrieve.
     * @return Pointer to the ISurface representing the sprite, or NULL if the index is invalid.
     */
    ISurface* fromIndex(Uint32 index);

    /**
     * @brief Create a new sprite index for a given rectangle.
     *
     * @param rect The rectangle defining the area of the new sprite.
     * @return The index of the newly created sprite.
     */
    int newSprite(SDL_Rect rect);

    /**
     * @brief Create a new sprite index for a given surface.
     *
     * @param surf The surface for the new sprite.
     * @return The index of the newly created sprite.
     */
    int newSprite(SDL_Surface* surf);

    /**
     * @brief Blit a sprite directly without saving any surfaces to memory.
     *
     * @param rect The rectangle defining the area of the sprite.
     * @param dest The destination SDL_Surface to blit the sprite onto.
     * @param x The x-coordinate position to blit the sprite.
     * @param y The y-coordinate position to blit the sprite.
     */
    void ezBlit(SDL_Rect rect, SDL_Surface* dest, int x, int y);

    /**
     * @brief Spritesheet constructor.
     *
     * Constructs a Spritesheet object using the provided ISurface pointer.
     *
     * @param sheet Pointer to the ISurface representing the spritesheet.
     */
    Spritesheet(ISurface* sheet);

    /**
     * @brief Spritesheet constructor overload.
     *
     * Constructs a Spritesheet object using the provided image file path.
     *
     * @param path The path to the image file containing the spritesheet.
     */
    Spritesheet(const char* path);

    /**
     * @brief Spritesheet destructor.
     */
    ~Spritesheet();

private:
    ISurface* m_sheet;                /**< Pointer to the ISurface representing the spritesheet. */
    std::vector<ISurface> m_sprites;  /**< Vector containing ISurface objects representing sprites. */
};
