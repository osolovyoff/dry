#pragma once
#include <mutex>
#include <algorithm>
#include <windows.h>

#include <dry/system_hook/services/services.h>

class SystemHook
{
public:
    SystemHook() = default;

    void trap(HINSTANCE instance);
    void leave();

private:
    friend LRESULT CALLBACK hook_procedure(int nCode, WPARAM wParam, LPARAM lParam);
    static bool             is_caps();

private:
    HHOOK           _keyboard_hook;
    static Services _services;
};