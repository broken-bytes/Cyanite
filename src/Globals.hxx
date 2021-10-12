#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define DLL_EXPORT __declspec( dllexport )
#ifndef UNICODE
#define UNICODE
#endif 
typedef HWND Window;
#else
#define DLL_EXPORT 
#endif



