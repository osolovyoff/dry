#pragma once
#include <chrono>
#include <string>

class TemporaryStorage
{
public:
    TemporaryStorage() = default;
    ~TemporaryStorage() = default;

    void         storage(std::wstring s);
    std::wstring get();

private:
    std::wstring _data;
};