#include <stdint.h>

struct {

} typedef GameControllerEvent;


void NextEvent(GameControllerEvent* event);

void InitSDL(uint32_t systems);

void NextGameControllerEvent(GameControllerEvent* event);

