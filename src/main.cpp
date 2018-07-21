#include "sdl2-boilerplate/boilerplate.h"

int main() {

	bool running = true;

	Input input;
	Graphics graphics = Graphics("SDL2 Boilerplate", 640, 480);
	SDL_Event e;

	// Main loop
	while (running) {
		input.pollEvents(e);
		// Check keyboard input
		if (input.wasKeyPressed(SDL_SCANCODE_Q)) running = false;

		// Render graphics to the screen
		graphics.clear();
		graphics.present();
	}

	return 0;
}
