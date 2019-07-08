#include "informer.h"

void Informer::check_title()
{
    const HWND hwnd = GetForegroundWindow();
    GetWindowText(hwnd, _buffer, MAX_BUFFER_SIZE);

    const std::wstring title = _buffer;
    if (title.empty())
        return;

    if (title != _last_title)
    {
        _last_title = title;
        //logger << std::endl << title << '|';
    }
}
