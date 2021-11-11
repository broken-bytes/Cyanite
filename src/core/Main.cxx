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

SDL_Window* mainWindow;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int main(int argc, char** argv) {
        printf("%s\n", "MAIN");
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
        printf("%s\n", SDL_GetError());
        
		mainWindow = window;

		SDL_Event event;
		str << quit;

		while (!quit) {
			SDL_PollEvent(&event);

			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			}
		}

		SDL_DestroyWindow(mainWindow);
		std::exit(0);
	}

#ifdef __cplusplus
}
#endif // __cplusplus

