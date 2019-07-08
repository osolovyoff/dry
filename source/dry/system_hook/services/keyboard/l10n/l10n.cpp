#include "l10n.h"

L10n::L10n()
{
    std::vector<std::shared_ptr<Lang>> list =
    {
        { std::make_shared<RusLang>() },
        { std::make_shared<EngLang>() },
    };

    for (auto& lang : list)
    {
        const auto key = lang->get_layout_code();
        _languages[key] = lang;
    }
}

std::wstring L10n::translate(const std::wstring& keyscan)
{
    TCHAR szKeyboard[KL_NAMELENGTH];
    GetKeyboardLayoutName(szKeyboard);

    const std::wstring layout = szKeyboard;
    auto lang_iter = _languages.find(layout);
    if (lang_iter != _languages.end())
    {
        const auto value = lang_iter->second->get_value(keyscan);
        return value;
    }
    return std::wstring();
}
