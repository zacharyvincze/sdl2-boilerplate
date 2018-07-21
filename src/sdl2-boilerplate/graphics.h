#pragma once

#include <string>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class Graphics {
public:
	Graphics(std::string title, int window_width, int window_height);
	~Graphics();

	void clear();
	void present();
	void pixel(int x, int y);
	void rect(SDL_Rect& rect);

	void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void destroyTexture(SDL_Texture* texture);

	SDL_Texture* loadImage(std::string file);
	void render(SDL_Texture* source, SDL_Rect* source_rect, SDL_Rect* destination_rect);
private:
	std::map<std::string, SDL_Texture*> sprite_sheets;

	SDL_Window* window;
	SDL_Renderer* renderer;
};