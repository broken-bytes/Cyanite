#include <thread>

#include "include/Info.h"

uint8_t cpuCores(void) {
    return std::thread::hardware_concurrency();
}
