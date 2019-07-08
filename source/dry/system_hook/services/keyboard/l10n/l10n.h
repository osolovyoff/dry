#pragma once
#include <map>
#include <vector>
#include <memory>
#include <Windows.h>

#include "lang\eng.h"
#include "lang\rus.h"

class L10n
{
    using KeyboardLayout = std::wstring;

public:
    L10n();

    std::wstring translate(const std::wstring& keyscan);

private:
    std::map<KeyboardLayout, std::shared_ptr<Lang>> _languages;
};