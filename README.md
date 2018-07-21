# SDL2 Boilerplate
This SDL2 boilerplate provides a quick way to setup and prototype small SDL2 projects.

## Dependencies
- **SDL2**: `sudo apt-get install libsdl2-dev` for most Linux distributions or `brew install sdl2` on MacOS.
- **SDL2_image**: `sudo apt-get install libsdl2-image-dev` for most Linux distributions or `brew install sdl2-image` on MacOS

## Usage
1. Be sure to `#include "sdl2-boilerplate/boilerplate.h"` to be able to use any of the boilerplate's functions (This file is already included in `main.cpp`)
2. The main loop is already setup in `main.cpp`.  It includes basic commands for initializing the SDL2 library, creating a window, polling user events, checking for keypresses, and rendering graphics to the screen.
3. Use `make` in the root project directory to compile your project into the `bin` folder.

## Functions
#### Input
- `pollEvents(SDL_Event &e)`: **Checks for any keyup or keydown events**
- `bool wasKeyPressed(SDL_Scancode key)`: **Checks if a certain key was pressed**
- `bool wasKeyHeld(SDL_Scancode key)`: **Checks if a certain was held down**
- `bool wasKeyReleased(SDL_Scancode key)`: **Checks if a certain key was released**
- `void beginNewFrame()`: **Resets values stored in the releasedKeys and heldKeys array**

#### Graphics
- Graphics(std::string title, int window_width, int window_height): **Initializes SDL2 and creates both a windows and a renderer with a specified size**
- `void clear()`: **Clears all pixels in the graphics buffer (currently with the color black (#000000))**
- `void present()`: **Renders data stored in the graphics buffer to the screen**
- `void pixel(int x, int y)`: **Draws a single pixel at a specified coordinate**
- `void rect(SDL_Rect& rect)`: **Draws an SDL rectangle**
- `void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)`: **Sets the renderer's draw color and alpha**
- `void destroyTexture(SDL_Texture* texture)`: **Deallocates SDL_Texture pointer**
- `SDL_Texture* loadImage(std::string file)`: **Creates an SDL_Texture from an image file**
- `void render(SDL_Texture* source, SDL_Rect* source_rect, SDL_Rect* destination_rect)`: **Draws an SDL_Texture, the source rect is used to determine which part of the texture will be drawn and the destination rect is used to determine where the image will be drawn on the screen**
