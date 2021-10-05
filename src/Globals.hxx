#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#ifndef UNICODE
#define UNICODE
#endif 
typedef HWND Window;
#endif



