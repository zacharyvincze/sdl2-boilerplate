#include "input.h"

void Input::beginNewFrame() {
	this->releasedKeys.clear();
	this->heldKeys.clear();
}

void Input::pollEvents(SDL_Event &e) {
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
			case SDL_KEYDOWN:
				if (!e.key.repeat)
					this->keyDownEvent(e);
				break;
			case SDL_KEYUP:
				this->keyUpEvent(e);
				break;
			case SDL_MOUSEMOTION:
				mouseX = e.motion.x;
				mouseY = e.motion.y;
			default:
				break;
		}
	}
}

void Input::keyUpEvent(SDL_Event &e) {
	this->releasedKeys[e.key.keysym.scancode] = true;
	this->heldKeys[e.key.keysym.scancode] = false;
}

void Input::keyDownEvent(SDL_Event &e) {
	this->pressedKeys[e.key.keysym.scancode] = true;
	this->heldKeys[e.key.keysym.scancode] = true;
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->releasedKeys[key];
}

bool Input::wasKeyHeld(SDL_Scancode key) {
	return this->heldKeys[key];
}

bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->pressedKeys[key];
}

int Input::getMouseX() {
	return mouseX;
}

int Input::getMouseY() {
	return mouseY;
}