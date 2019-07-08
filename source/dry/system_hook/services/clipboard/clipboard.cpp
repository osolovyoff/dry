#include "clipboard.h"
#include <iostream>

Clipboard::Text Clipboard::get()
{
    const bool is_opened = OpenClipboard(NULL);
    if (is_opened)
    {
        const HANDLE handle = GetClipboardData(CF_TEXT);

        const Text::value_type* ptr_text = static_cast<const char*>(GlobalLock(handle));
        const size_t            size_of_text = std::strlen(ptr_text);

        if (size_of_text <= MAX_BUFFER_TEXT_SIZE)
            _text = Text(ptr_text);

        GlobalUnlock(handle);
        CloseClipboard();
    }
    return _text;
}

void Clipboard::set(Text& text)
{
    const bool is_opened = OpenClipboard(NULL);
    if (is_opened)
    {
        EmptyClipboard();
        HGLOBAL clipbuffer = GlobalAlloc(GMEM_DDESHARE, text.size());

        char* buffer = (char*)GlobalLock(clipbuffer);
        strcpy(buffer, LPCSTR(text.c_str()));
        GlobalUnlock(clipbuffer);
        SetClipboardData(CF_TEXT, clipbuffer);
        CloseClipboard();
    }
}