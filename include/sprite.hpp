#pragma once

#include <SDL2/SDL.h>
#include <isurface.hpp>
#include <spritesheet.hpp>

/**
 * @class Sprite
 * @brief Sprite class
 *
 * The Sprite class represents a sprite and provides functionalities to render
 * the sprite onto a surface and change its texture index.
 */
class Sprite {
public:
    float m_pos_x;  /**< The x-coordinate position of the sprite. */
    float m_pos_y;  /**< The y-coordinate position of the sprite. */
    
    /**
     * @brief Sprite constructor.
     *
     * Constructs a Sprite object using the provided Spritesheet.
     *
     * @param sheet The Spritesheet to use for the sprite.
     */
    Sprite(Spritesheet* sheet);

    /**
     * @brief Render the sprite onto a surface.
     *
     * Renders the sprite onto the specified destination surface.
     *
     * @param dest The surface where the sprite should be rendered.
     */
    void render(SDL_Surface* dest);

    /**
     * @brief Change the texture index used by the sprite.
     *
     * Changes the texture index to be used by the sprite.
     *
     * @param index The index of the new texture.
     */
    void setTexture(Uint32 index);

private:
    Spritesheet* m_sheet;  /**< Pointer to the Spritesheet used by the sprite. */
    Uint32 m_current_tex;  /**< The index of the current texture used by the sprite. */
};
