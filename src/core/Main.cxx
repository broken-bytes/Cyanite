#include <cstdint>
#include <memory>
#include <stdio.h>
#include <fcntl.h>
#include <thread>
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_syswm.h>
#include <SDL_vulkan.h>
#include <iostream>
#include <string>
#include <sstream>


constexpr char NAME[] = "Cyanite";
constexpr char VERSION[] = "0.01a";


#ifdef __APPLE__
constexpr char ASSEMBLY[] = "./libCyaniteAssembly.dylib";
#endif
#ifdef _WIN32
constexpr char ASSEMBLY[] = "./CyaniteAssembly.dll";
#endif

constexpr char ASSEMBLY_MAIN[] = "AssemblyInit";
constexpr char ASSEMBLY_UPDATE[] = "AssemblyUpdate";



SDL_Window* mainWindow;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int main(int argc, char** argv) {
    for(int x = 0; x < argc; x++) {
        printf("%s\n", argv[x]);
    }
    
    auto handle = SDL_LoadObject(ASSEMBLY);
    auto initFunc = (void(*)())SDL_LoadFunction(handle, ASSEMBLY_MAIN);
    auto updateFunc = (void(*)())SDL_LoadFunction(handle, ASSEMBLY_UPDATE);
    initFunc();
    
    bool quit = false;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    std::stringstream str;
    str << NAME << " - " << VERSION;
    SDL_DisplayMode mode;
    SDL_GetDesktopDisplayMode(1, &mode);
    auto Width = mode.w;
    auto Height = mode.h;
    
    auto* window =
    SDL_CreateWindow(
                     str.str().c_str(),
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     1280,
                     768,
                     SDL_WINDOW_VULKAN
                     );
    
    mainWindow = window;

    
    SDL_Event event;
    uint64_t frameId = 0;
    while (!quit) {
        while(SDL_PollEvent(&event)) {
            
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }
        updateFunc();

    }
    
    SDL_DestroyWindow(mainWindow);
    std::exit(0);
}

#ifdef __cplusplus
}
#endif // __cplusplus

