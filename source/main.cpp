#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "dry/dry.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Dry dry(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    dry.run();
    return 0;
}