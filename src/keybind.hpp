#pragma once

#include "common.hpp"

#include "utils/keycode.hpp"

class keybind
{
public:
    keybind() = default;
    keybind(std::string  name, const keycode& key);
    keybind(const keybind&) = default;
    keybind(keybind&&) = default;
    explicit keybind(std::string  name) noexcept;
    explicit keybind(const keycode& key) noexcept;
    virtual ~keybind() = default;

    keybind& operator=(const keybind& other) noexcept = default;
    keybind& operator=(const keycode& key) noexcept {
        m_key = key;

        return *this;
    }
    keybind& operator=(keybind&& other) noexcept = default;
    keybind& operator=(const std::string& name) noexcept {
        m_name = name;

        return *this;
    }
    keybind& operator=(std::string&& name) noexcept {
        m_name = std::move(name);

        return *this;
    }
    keybind& operator=(const char* name) noexcept {
        m_name = name;

        return *this;
    }
    keybind& operator=(const int key) noexcept {
        m_key = static_cast<keycode>(key);

        return *this;
    }
    keybind& operator=(const int& key) noexcept {
        m_key = static_cast<keycode>(key);

        return *this;
    }
    keybind& operator=(const unsigned int& key) noexcept {
        m_key = static_cast<keycode>(key);

        return *this;
    }


    bool catch_key();
    void set_name(const std::string& name) noexcept;
    void set_key(const keycode& key) noexcept;
    void set_waiting_for_key(const bool waiting) noexcept {
        m_waiting_for_key = waiting;
    }

    [[nodiscard]] const std::string& get_name() const noexcept;
    [[nodiscard]] const keycode& get_key() const noexcept;

    [[nodiscard]] std::string to_string() const noexcept;

    [[nodiscard]] bool is_waiting_for_key() const noexcept {
        return m_waiting_for_key;
    }

    std::string m_name;
private:
    keycode m_key = keycode::none;

    bool m_waiting_for_key{ false };
};