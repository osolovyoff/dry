#include "temporary_storage.h"

void TemporaryStorage::storage(std::wstring s)
{
    
    _data += s;
}

std::wstring TemporaryStorage::get()
{
    if (true)
    {

        return _data;
    }
    return std::wstring();
}
