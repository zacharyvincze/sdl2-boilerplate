#include "graphics.h"

Graphics::Graphics(std::string title, int window_width, int window_height) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_FULLSCREEN_DESKTOP);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, window_width, window_height);
	SDL_ShowCursor(SDL_FALSE);
}

Graphics::~Graphics() {
	for (std::map<std::string, SDL_Texture*>::iterator i = this->sprite_sheets.begin();
		i != this->sprite_sheets.end(); i++) {
		SDL_DestroyTexture(i->second);
	}

	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);

	this->renderer = NULL;
	this->window = NULL;
}

void Graphics::clear() {
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 1);
	SDL_RenderClear(this->renderer);
}

SDL_Texture* Graphics::loadImage(std::string file) {
	if (this->sprite_sheets.count(file) == 0) {
		SDL_Surface* surface = IMG_Load(file.c_str());
		this->sprite_sheets[file] = SDL_CreateTextureFromSurface(this->renderer, surface);
		SDL_FreeSurface(surface);
	}

	return this->sprite_sheets[file];
}

void Graphics::render(SDL_Texture *source, SDL_Rect *source_rect, SDL_Rect *destination_rect) {
	if (source_rect) {
		destination_rect->w = source_rect->w;
		destination_rect->h = source_rect->h;
	}

	SDL_RenderCopy(this->renderer, source, source_rect, destination_rect);
}

void Graphics::present() {
	SDL_RenderPresent(this->renderer);
}

void Graphics::pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
	SDL_SetRenderDrawColor(this->renderer, r, g, b, 1);
	SDL_RenderDrawPoint(this->renderer, x, y);
}