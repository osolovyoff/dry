#pragma once
#include <map>

class Lang
{
public:
    using Value = std::wstring;
    using KeyCode = std::wstring;

    Lang()
    {
        _keys[L"Tab"]         = L"[TAB]";
        _keys[L"tab"]         = L"[TAB]";
        _keys[L"Delete"]      = L"[DEL]";
        _keys[L"delete"]      = L"[DEL]";
        _keys[L"Backspace"]   = L"[BS]";
        _keys[L"backspace"]   = L"[BS]";
        _keys[L"Enter"]       = L"[ENTER]";
        _keys[L"enter"]       = L"[ENTER]";
        _keys[L"Space"]       = L"[SPACE]";
        _keys[L"space"]       = L"[SPACE]";
        _keys[L"Left alt"]    = L"[L ALT] ";
        _keys[L"left alt"]    = L"[L ALT] ";
        _keys[L"Right Alt"]   = L"[R ALT] ";
        _keys[L"right alt"]   = L"[R ALT] ";
        _keys[L"Caps Lock"]   = L"[CAPS]";
        _keys[L"caps lock"]   = L"[CAPS]";
        _keys[L"Right Shift"] = L"[R SHIFT] ";
        _keys[L"right shift"] = L"[R SHIFT] ";
        _keys[L"Shift"]       = L"[L SHIFT]";
        _keys[L"shift"]       = L"[L SHIFT]";
        _keys[L"Ctrl"]        = L"[L CTRL]";
        _keys[L"ctrl"]        = L"[L CTRL]";
        _keys[L"Right Ctrl"]  = L"[R CTRL]";
        _keys[L"right ctrl"]  = L"[R CTRL]";
        _keys[L"Page up"]     = L"[PageUp]";
        _keys[L"page up"]     = L"[PageUp]";
        _keys[L"Page down"]   = L"[PageDown]";
        _keys[L"page down"]   = L"[PageDown]";
        _keys[L"Up"]          = L"[Up]";
        _keys[L"up"]          = L"[Up]";
        _keys[L"Down"]        = L"[Down]";
        _keys[L"down"]        = L"[Down]";
        _keys[L"Left"]        = L"[Left]";
        _keys[L"left"]        = L"[Left]";
        _keys[L"Right"]       = L"[Right]";
        _keys[L"right"]       = L"[Right]";
        _keys[L"Left windows"]= L"[L Win]";
        _keys[L"left windows"]= L"[L Win]";
        _keys[L"Right windows"] = L"[R Win]";
        _keys[L"right windows"] = L"[R Win]";
        _keys[L"Q"]           = L"Q";
        _keys[L"W"]           = L"W";
        _keys[L"E"]           = L"E";
        _keys[L"R"]           = L"R";
        _keys[L"T"]           = L"T";
        _keys[L"Y"]           = L"Y";
        _keys[L"U"]           = L"U";
        _keys[L"I"]           = L"I";
        _keys[L"O"]           = L"O";
        _keys[L"P"]           = L"P";
        _keys[L"{"]           = L"{";
        _keys[L"}"]           = L"}";
        _keys[L"|"]           = L"|";
        _keys[L"A"]           = L"A";
        _keys[L"S"]           = L"S";
        _keys[L"D"]           = L"D";
        _keys[L"F"]           = L"F";
        _keys[L"G"]           = L"G";
        _keys[L"H"]           = L"H";
        _keys[L"J"]           = L"J";
        _keys[L"K"]           = L"K";
        _keys[L"L"]           = L"L";
        _keys[L":"]           = L":";
        _keys[L"\""]          = L"\"";
        _keys[L"Z"]           = L"Z";
        _keys[L"X"]           = L"X";
        _keys[L"C"]           = L"C";
        _keys[L"V"]           = L"V";
        _keys[L"B"]           = L"B";
        _keys[L"N"]           = L"N";
        _keys[L"M"]           = L"M";
        _keys[L"<"]           = L"<";
        _keys[L">"]           = L">";
        _keys[L"?"]           = L"?";
        _keys[L"q"]           = L"q";
        _keys[L"w"]           = L"w";
        _keys[L"e"]           = L"e";
        _keys[L"r"]           = L"r";
        _keys[L"t"]           = L"t";
        _keys[L"y"]           = L"y";
        _keys[L"u"]           = L"u";
        _keys[L"i"]           = L"i";
        _keys[L"o"]           = L"o";
        _keys[L"p"]           = L"p";
        _keys[L"["]           = L"[";
        _keys[L"]"]           = L"]";
        _keys[L"|"]           = L"|";
        _keys[L"a"]           = L"a";
        _keys[L"s"]           = L"s";
        _keys[L"d"]           = L"d";
        _keys[L"f"]           = L"f";
        _keys[L"g"]           = L"g";
        _keys[L"h"]           = L"h";
        _keys[L"j"]           = L"j";
        _keys[L"k"]           = L"k";
        _keys[L"l"]           = L"l";
        _keys[L";"]           = L":";
        _keys[L"'"]           = L"'";
        _keys[L"z"]           = L"z";
        _keys[L"x"]           = L"x";
        _keys[L"c"]           = L"c";
        _keys[L"v"]           = L"v";
        _keys[L"b"]           = L"b";
        _keys[L"n"]           = L"n";
        _keys[L"m"]           = L"m";
        _keys[L","]           = L",";
        _keys[L"."]           = L".";
        _keys[L"/"]           = L"/";          
    }

    const Value& get_value(const KeyCode& code)
    {
        return _keys[code];
    }

    virtual std::wstring get_layout_code() const = 0;

protected:
    std::map<KeyCode, Value> _keys;
};
 