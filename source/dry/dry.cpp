#include "dry.h"

Dry::Dry(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int cmd_show)
{
    _instance = instance;
    _prev_instance = prev_instance;
    _cmd_line = cmd_line;
    _cmd_show = cmd_show;
}

void Dry::run()
{
    _system_hook.trap(_instance);

    while (_is_run)
    {
        if (PeekMessage(&_msg, NULL, 0, 0, PM_NOREMOVE))
        {
            TranslateMessage(&_msg);
            DispatchMessage(&_msg);
        }
        else
        {
            //_informer.check_title();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_TIME));
        std::this_thread::yield();
    }
    _system_hook.leave();
}