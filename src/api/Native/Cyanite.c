#include "Cyanite.h"
#ifdef _WIN32
#include <Windows.h>

typedef int(__stdcall* StartFunc)(Update);
typedef void(__stdcall* EventPollFuncPtr)(EventFunc);
typedef int(__stdcall* EndFunc)();

EventPollFuncPtr EventPollFunc;
EndFunc CyaniteEndFunc;


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

	CyaniteEndFunc = (EndFunc)GetProcAddress(
		engineModule,
		"CyaniteDeinit");

	CyaniteCore(update);
}

void CyanitePollEvent(EventFunc e) {
	EventPollFunc(e);
}

void CyaniteDeinit() {
	CyaniteEndFunc();
}

#endif
