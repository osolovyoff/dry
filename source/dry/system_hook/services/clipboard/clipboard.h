#pragma once
#include <string>
#include <Windows.h>

#include <dry/system_hook/services/service.h>

class Clipboard: public IService
{
    using Text = std::string;

    static constexpr size_t MAX_BUFFER_TEXT_SIZE = 200U;

public:
    Clipboard() = default;
    ~Clipboard() = default;

    Text get();
    void set(Text&);

private:
    std::string _text;
};

using ClipboardShared = std::unique_ptr<Clipboard>;