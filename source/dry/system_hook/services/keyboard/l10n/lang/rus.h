#pragma once
#include "lang.h"

class RusLang : public Lang
{
public:
    RusLang()
    {
        _keys[L"Q"] = L"Й";
        _keys[L"W"] = L"Ц";
        _keys[L"E"] = L"У";
        _keys[L"R"] = L"К";
        _keys[L"T"] = L"Е";
        _keys[L"Y"] = L"Н";
        _keys[L"U"] = L"Г";
        _keys[L"I"] = L"Ш";
        _keys[L"O"] = L"Щ";
        _keys[L"P"] = L"З";
        _keys[L"{"] = L"Х";
        _keys[L"}"] = L"Ъ";
        _keys[L"|"] = L"/";
        _keys[L"A"] = L"Ф";
        _keys[L"S"] = L"Ы";
        _keys[L"D"] = L"В";
        _keys[L"F"] = L"А";
        _keys[L"G"] = L"П";
        _keys[L"H"] = L"Р";
        _keys[L"J"] = L"О";
        _keys[L"K"] = L"Л";
        _keys[L"L"] = L"Д";
        _keys[L":"] = L"Ж";
        _keys[L"\""] = L"Э";
        _keys[L"Z"] = L"Я";
        _keys[L"X"] = L"Ч";
        _keys[L"C"] = L"С";
        _keys[L"V"] = L"М";
        _keys[L"B"] = L"И";
        _keys[L"N"] = L"Т";
        _keys[L"M"] = L"Ь";
        _keys[L"<"] = L"Б";
        _keys[L">"] = L"Ю";
        _keys[L"?"] = L",";
        _keys[L"q"] = L"й";
        _keys[L"w"] = L"ц";
        _keys[L"e"] = L"у";
        _keys[L"r"] = L"к";
        _keys[L"t"] = L"е";
        _keys[L"y"] = L"н";
        _keys[L"u"] = L"г";
        _keys[L"i"] = L"ш";
        _keys[L"o"] = L"щ";
        _keys[L"p"] = L"з";
        _keys[L"["] = L"х";
        _keys[L"]"] = L"ъ";
        _keys[L"|"] = L"\\";
        _keys[L"a"] = L"ф";
        _keys[L"s"] = L"ы";
        _keys[L"d"] = L"в";
        _keys[L"f"] = L"а";
        _keys[L"g"] = L"п";
        _keys[L"h"] = L"р";
        _keys[L"j"] = L"о";
        _keys[L"k"] = L"л";
        _keys[L"l"] = L"д";
        _keys[L";"] = L"ж";
        _keys[L"'"] = L"э";
        _keys[L"z"] = L"я";
        _keys[L"x"] = L"ч";
        _keys[L"c"] = L"с";
        _keys[L"v"] = L"м";
        _keys[L"b"] = L"и";
        _keys[L"n"] = L"т";
        _keys[L"m"] = L"ь";
        _keys[L","] = L"б";
        _keys[L"."] = L"ю";
        _keys[L"/"] = L".";
    }

    std::wstring get_layout_code() const override { return L"00000419"; }
};