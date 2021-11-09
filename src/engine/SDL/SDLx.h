#include <stdint.h>

struct SDLxControllerEvent {
	uint8_t controllerId;
	uint64_t eventId;
	uint64_t evenValue;
} typedef SDLxControllerEvent;


void SDLxInit(void* winHandle);
void SDLxPeekEvent(SDLxControllerEvent* event);