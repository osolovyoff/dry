#pragma once
#include <Windows.h>

#include <dry/system_hook/system_hook.h>

class Dry
{
    const long long UPDATE_TIME = 1000 / 30; // 30 FPS per Second

public:
    Dry(HINSTANCE, HINSTANCE, LPSTR, int);

    void run();

private:
    MSG  _msg;
    bool _is_run = { true };

protected:
    SystemHook _system_hook;

private:
    HINSTANCE _instance;
    HINSTANCE _prev_instance;
    LPSTR     _cmd_line;
    int       _cmd_show;
};