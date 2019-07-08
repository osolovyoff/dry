#pragma once
#include <mutex>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ostream>
#include <iostream>
#include <unordered_map>

#include <Windows.h>

#include <dry/system_hook/services/service.h>

#define FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))
#define CODELINE __LINE__
#define CODEINFO FILENAME << '[' << CODELINE << "]| "

class Logger: public IService
{
    const std::string filename = { "mib.data" };

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    using LoggerManip = Logger&(*)(Logger&);
    using CoutType = std::basic_ostream<TCHAR, std::char_traits<TCHAR> >;
    using StandardEndLine = CoutType& (*)(CoutType&);

public:
    Logger() = default;

    Logger& operator<<(Logger&);
    Logger& operator<<(LoggerManip manip);
    Logger& operator<<(StandardEndLine manip);

    template <class T>
    Logger& operator<<(const T& out);

    Logger& write(TCHAR* data, size_t size);

    static std::string time_now()
    {
        const auto now = std::chrono::system_clock::now();
        const auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y/%m/%d %X| ");

        return ss.str();
    }

private:
    std::wofstream _fout;
};

inline Logger& Logger::operator<<(Logger&)
{
    return *this;
}

inline Logger& Logger::operator<<(LoggerManip manip)
{
    return manip(*this);
}

inline Logger& Logger::operator<<(StandardEndLine manip)
{
    _fout.open(filename, std::ios::app);
    if (_fout.is_open())
        manip(_fout);
    _fout.close();
    return *this;
}

inline Logger& Logger::write(TCHAR* data, size_t size)
{
    _fout.open(filename, std::ios::app);
    if (_fout.is_open())
        _fout.write(data, size);
    _fout.close();
    return *this;
}

template <class T>
inline Logger& Logger::operator<<(const T& out)
{
    _fout.open(filename, std::ios::app);
    if (_fout.is_open())
        _fout << out;
    _fout.close();
    return *this;
}

extern Logger Loggerger;