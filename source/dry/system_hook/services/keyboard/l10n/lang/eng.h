#pragma once
#include "lang.h"

class EngLang: public Lang
{
public:
    EngLang() = default;

    std::wstring get_layout_code() const override { return L"00000409"; }
};