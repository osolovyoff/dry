//#pragma once
//#include <mutex>
//#include <algorithm>
//#include <windows.h>
//
////#include "dry/service_manager/service/logger/logger.h"
////#include "dry/service_manager/service/clipboard/clipboard.h"
////#include "l10n/l10n.h"
//
//class Keylogger
//{
//public:
//    Keylogger() = default;
//
//    void trap(HINSTANCE instance);
//    void leave();
//
//private:
//    friend LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam);
//    static bool is_caps();
//
//private:
//    HHOOK     _keyboard_hook;
//};