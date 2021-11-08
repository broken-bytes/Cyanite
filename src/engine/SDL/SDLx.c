#include "SDLx.h"
#include "SDL.h"
#include "SDL_events.h"

void SDLxInit(void* winHandle) {
	SDL_CreateWindowFrom(winHandle);
	SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC);
}

void SDLxPeekEvent(SDLxControllerEvent* event) {
	event = NULL;
	SDL_Event* sdlEvent = NULL;
	SDL_PollEvent(sdlEvent);
	return event;
}