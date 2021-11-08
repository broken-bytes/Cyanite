#pragma once
#define DllExport __declspec( dllexport )
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef __apple_build_version__
#define SWIFT_NAME(X) __attribute__((swift_name(#X)))
#else
#define SWIFT_NAME(X)
#endif
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	enum EventType {
		EVENT_MOUSE_MOVE,
		EVENT_MOUSE_BTN,
		EVENT_KEYBOARD_BTN,
		EVENT_CONTROLLER_BTN,
		EVENT_CONTROLLER_MOVE
	} typedef EventType;

	struct MouseMoveEvent {
		uint16_t X;
		uint16_t Y;
	} typedef MouseMoveEvent;

	struct MouseBtnEvent {
		uint8_t Btn;
	} typedef MouseBtnEvent;

	union EventData {
		MouseMoveEvent MouseMove;
		MouseBtnEvent MouseBtn;
	} typedef EventData;

	struct Event {
		EventType Type;
		EventData Data;
	} typedef Event;

	typedef void(*Update)();
	typedef void(__stdcall* EventFunc)(bool, Event*);


	DllExport void CyaniteInit(Update update)
		SWIFT_NAME(CyaniteInit(update:));
	DllExport void CyanitePollEvent(EventFunc)
		SWIFT_NAME(CyaniteInit(completion:));

#ifdef __cplusplus
}
#endif
