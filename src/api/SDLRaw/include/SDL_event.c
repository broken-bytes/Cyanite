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

const char* ModStr(char* str) {
    size_t len = strlen(str);
    size_t newLen = strlen(str) + 5;
    DWORD written = 0;
    char* newStr = malloc(len + 5);
    for(int x = 0; x < len; x++) {
        newStr[x] = str[x];
    }
    newStr[len] = 'x';

    for(int x = len; x < newLen - 1; x++) {
        newStr[x] = 'x';
    }
    
    newStr[newLen - 1] = '\0';
    return newStr;
}

void ModArr(int32_t* arr, size_t length) {
    for(int x = 0; x < length; x++) {
        arr[x] = arr[x] * arr[x];
    }
}
