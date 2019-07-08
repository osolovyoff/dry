#pragma once
#include <map>
#include <memory>
#include <typeindex>

#include "service.h"

class Services
{
public:
    Services() = default;

    template <class Service>
    void initialize()
    {
        std::lock_guard<std::mutex> lk(_mutex);
        Services::check<Service>();

        const auto index = Services::get_index<Task>();
        const auto& it = _map.find(index);
        if (it == _map.end())
            _map[index] = std::make_unique<Task>();
    }

    template <class Service>
    void release()
    {
        std::lock_guard<std::mutex> lk(_mutex);
        Services::check<Service>();

        const auto index = Services::get_index<Service>();
        const auto& it = _map.find(index);
        if (it != _map.end())
            _map[index].reset();
    }

    template <class Service>
    decltype(auto) get()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        Services::check<Service>();

        const auto index = Services::get_index<Service>();
        const auto& it = _map.find(index);
        if (it == _map.end())
            _map[index] = std::make_unique<Service>();

        return reinterpret_cast<std::unique_ptr<Service>&>(_map[index]);
    }

private:
    template <class Service>
    constexpr std::type_index get_index() const
    {
        return std::type_index(typeid(Service));
    }

    template <class Service>
    constexpr void check() const
    {
        constexpr bool is_derived = std::is_base_of<IService, Service>::value;
        constexpr bool is_interface = std::is_same<IService, Service>::value;

        static_assert( is_derived && !is_interface, "Derived class must be based on ITask");
    }

private:
    std::mutex                                           _mutex;
    std::map<std::type_index, std::unique_ptr<IService>> _map;
};