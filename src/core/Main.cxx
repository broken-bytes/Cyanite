#include <cstdint>
#include <io.h>
#include <memory>
#include <stdio.h>
#include <fcntl.h>
#include <thread>
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_syswm.h>
#include "Main.hxx"
#include <Windows.h>
#include <iostream>
//#include <InputEvent.hxx>
//#include <MouseEvent.hxx>


typedef int(__stdcall* StartFunc)(HWND);

constexpr char NAME[] = "Cyanite";
constexpr char VERSION[] = "0.01a";

SDL_Window* mainWindow;

void RunSwiftEngine(HWND hwnd);
void HandleInput();

void CyaniteInit(Update update) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
	std::stringstream str;
	str << NAME << " - " << VERSION;
	auto* window =
		SDL_CreateWindow(
			str.str().c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			0
		);
	SDL_SysWMinfo winInfo = {};
	SDL_GetWindowWMInfo(window, &winInfo);
	mainWindow = window;
#ifdef _WIN32
	HWND hwnd = winInfo.info.win.window;
	bool quit = false;
	SDL_Event event;

	while(!quit) {
		update();
	}

#endif // _WIN32
}

void CyanitePollEvent(EventFunc completion) {
	SDL_Event event = {};
	Event e = {};
	auto hasEvent = SDL_PollEvent(&event);
	if (hasEvent) {
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			e.Type = EVENT_MOUSE_MOVE;
			e.Data.MouseMove = MouseMoveEvent{ };
			e.Data.MouseMove.X = event.motion.x;
			e.Data.MouseMove.Y = event.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			e.Type = EVENT_MOUSE_BTN;
			e.Data.MouseBtn = MouseBtnEvent{ };
			e.Data.MouseBtn.Btn = event.button.which;
			break;
		default:
			break;
		}
	}
	completion(hasEvent, &e);
}

void HandleInput() {

}

void RunSwiftEngine(HWND hwnd) {
	/* get handle to dll */
	

	//FreeLibrary(hGetProcIDDLL);

	/* The return val from the dll */
}
