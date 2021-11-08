#include "Cyanite.h"
#ifdef _WIN32
#include <Windows.h>

typedef int(__stdcall* StartFunc)(Update);
typedef void(__stdcall* EventPollFuncPtr)(EventFunc);

EventPollFuncPtr EventPollFunc;

void CyaniteInit(Update update) {
	//FreeConsole();
    HINSTANCE engineModule =
		LoadLibraryA("Cyanite.dll");

	
	StartFunc CyaniteCore = (StartFunc)GetProcAddress(
		engineModule,
		"CyaniteInit");

	EventPollFunc = (EventPollFuncPtr)GetProcAddress(
		engineModule,
		"CyanitePollEvent");

	CyaniteCore(update);
}

void CyanitePollEvent(EventFunc e) {
	EventPollFunc(e);
}
#endif
