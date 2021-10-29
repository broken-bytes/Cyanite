#include <cstdint>
#include <Globals.hxx>
#include <Windowsx.h>
#include <io.h>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <SDL.h>
#include <SDL_joystick.h>
#include <SDL_gamecontroller.h>
#include <thread>
//#include <InputEvent.hxx>
//#include <MouseEvent.hxx>


struct Event {
	uint64_t id;
	uint64_t value;
};


typedef int(__stdcall* StartFunc)(HWND);
typedef int(__stdcall* EventFunc)(int64_t, int64_t);
typedef int(__stdcall* EventDataFunc)(Event);

constexpr LPCSTR CLASS_NAME = "CYANITE_MAIN_WIN";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void RunSwiftEngine(HWND hwnd);
void HandleInput();

int main(int argc, char** argv) {
	//RunSwiftEngine(nullptr);
	return 0;
}


int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pCmdLine,
	int nCmdShow)
{
	// Register the window class.
	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass(&wc);

	// Create the window.


	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		"Cyanite 2022.0-rc",			// Window text
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // Parent window    
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	RECT winRect{};
	GetWindowRect(hwnd, &winRect);
	auto console = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD written;
	RunSwiftEngine(hwnd);

	// Run the message loop.

	MSG msg = { };
	while (GetMessage(&msg, nullptr, 0, 0))
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int test = 0;
	switch (uMsg)
	{

	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_MBUTTONDOWN:
		break;
	case WM_MBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_KEYUP:
	
		break;
	case WM_KEYDOWN:		
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	return 0;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void HandleInput() {
	SDL_Event ev = {};
	while (true) {
		int64_t value = 0;
		switch (ev.type) {
		case SDL_CONTROLLERAXISMOTION:
			value = ev.caxis.value;
			break;
		case SDL_JOYAXISMOTION:
			value = ev.jaxis.value;
			break;
		}
	}
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
