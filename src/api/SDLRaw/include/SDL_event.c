#include "SDL_event.h"
#include <Windows.h>

typedef int(*InitSDLFunc)(uint32_t);
typedef int(*EventSDLFunc)(GameControllerEvent*);


EventSDLFunc SDL_Event;

void InitSDL(uint32_t systems) {
    HINSTANCE lib = LoadLibraryA("./SDL2.dll");
    InitSDLFunc SDL_Init = (InitSDLFunc)GetProcAddress(lib, "SDL_Init");
    SDL_Event = (EventSDLFunc)GetProcAddress(lib, "SDL_PollEvent");

    SDL_Init(systems);
}

void NextEvent(GameControllerEvent* event) {
    SDL_Event(event);
}  

void NextGameControllerEvent(GameControllerEvent* event) {

}
