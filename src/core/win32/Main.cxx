#include <Globals.hxx>
#include <Windowsx.h>

#include <CyaniteEngine.hxx>

#include "InputEvent.hxx"
#include "MouseEvent.hxx"

constexpr LPCSTR CLASS_NAME = "CYANITE_MAIN_WIN";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

using namespace BrokenBytes::Cyanite::Engine;

std::unique_ptr<CyaniteEngine> engine;



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
		"Cyanite 2022.0-rc",    // Window text
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

	engine = std::make_unique<CyaniteEngine>(
		hwnd,
		static_cast<uint16_t>(std::floor(winRect.right - winRect.left)),
		static_cast<uint16_t>(std::floor(winRect.top - winRect.bottom))
		);


	// Run the message loop.

	MSG msg = { };
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		engine->Run();
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
		engine->AddEvent(new Events::MouseEvent{
			static_cast<uint16_t>(GET_X_LPARAM(lParam)),
			static_cast<uint16_t>(GET_Y_LPARAM(lParam)) });
		break;
	case WM_KEYUP:
		engine->AddEvent( new Events::InputEvent{
			KeyCode(wParam),
			false
			});
		break;
	case WM_KEYDOWN:
		engine->AddEvent(new Events::InputEvent{
			KeyCode(wParam),
			true
			});
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