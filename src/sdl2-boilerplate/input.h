#pragma once

#include <SDL2/SDL.h>
#include <map>

class Input {
public:
	void beginNewFrame();

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyHeld(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);

	int getMouseX();
	int getMouseY();

	void keyUpEvent(SDL_Event& e);
	void keyDownEvent(SDL_Event& e);

	void pollEvents(SDL_Event& e);
private:
	std::map<SDL_Scancode, bool> heldKeys;
	std::map<SDL_Scancode, bool> releasedKeys;
	std::map<SDL_Scancode, bool> pressedKeys;

	int mouseX, mouseY;
};