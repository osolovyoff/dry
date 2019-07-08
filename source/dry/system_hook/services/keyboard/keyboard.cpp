//#include "keyboard.h"
//
//HHOOK           Keyboard::_hook;
//KBDLLHOOKSTRUCT Keyboard::_keyboard;
//
//Keyboard::~Keyboard()
//{
//    if (_hook)
//        UnhookWindowsHookEx(_hook);
//}
//
//bool Keyboard::trap()
//{
//    _hook = SetWindowsHookEx(WH_KEYBOARD_LL,
//        [](int nCode, WPARAM wParam, LPARAM lParam)->LRESULT
//    {
//        if (nCode >= 0 && wParam == WM_KEYDOWN)
//        {
//            _keyboard = *((KBDLLHOOKSTRUCT*)lParam);
//            if (_keyboard.vkCode == VK_F1)
//            {
//
//            }
//        }
//        return CallNextHookEx(_hook, nCode, wParam, lParam);
//    }, NULL, 0);
//
//    return _hook != 0;
//}