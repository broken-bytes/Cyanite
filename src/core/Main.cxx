#include <cstdint>
#include <Globals.hxx>
#include <io.h>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <fcntl.h>
#include <thread>
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_syswm.h>
#include "../Main.hxx"
//#include <InputEvent.hxx>
//#include <MouseEvent.hxx>


struct Event {
	uint64_t id;
	uint64_t value;
} ;


typedef int(__stdcall* StartFunc)(HWND);
typedef int(__stdcall* EventFunc)(int64_t, int64_t);
typedef int(__stdcall* EventDataFunc)(Event);

constexpr char NAME[] = "Cyanite";
constexpr char VERSION[] = "0.01a";

void RunSwiftEngine(HWND hwnd);
void HandleInput();

int Cyanite(int argc, char** argv) {
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
#ifdef _WIN32
	HWND hwnd = winInfo.info.win.window;
	RunSwiftEngine(hwnd);
	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEMOTION:
			int mouseX = event.motion.x;
			int mouseY = event.motion.y;

			std::stringstream ss;
			ss << "X: " << mouseX << " Y: " << mouseY;

			SDL_SetWindowTitle(window, ss.str().c_str());
			break;
		}
	}
#endif // _WIN32
	return 0;
}

void HandleInput() {

}

void RunSwiftEngine(HWND hwnd) {
	/* get handle to dll */
	HINSTANCE hGetProcIDDLL =
		LoadLibrary("C:\\Users\\Marcel\\Documents\\Cyanite\\src\\api\\.build\\x86_64-unknown-windows-msvc\\debug\\CyaniteScripting.dll");


	/* get pointer to the function in the dll*/
	FARPROC startId = GetProcAddress(
		HMODULE(hGetProcIDDLL),
		"$s8Internal12createEngine4withySpySo6HWND__VG_tF");

	StartFunc SwiftStart = StartFunc(startId);
	/* The actual call to the function contained in the dll */
	int result = SwiftStart(hwnd);


	FARPROC addEventId = GetProcAddress(
		HMODULE(hGetProcIDDLL),
		"$s8Internal8addEvent2of4withys5Int64V_AFtF");

	//FreeLibrary(hGetProcIDDLL);

	/* The return val from the dll */
}
