#pragma once
#include <string>
#include <Windows.h>

#include "../logger/logger.h"

class Informer
{
    static const size_t MAX_BUFFER_SIZE = 512;

public:
    void check_title();

private:
    TCHAR        _buffer[MAX_BUFFER_SIZE];
    std::wstring _last_title;
};