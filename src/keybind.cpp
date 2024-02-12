#include "keybind.hpp"

#include <imgui.h>
#include <utility>

keybind::keybind(std::string name, const keycode& key)
    : m_name(std::move(name)), m_key(key)
{
}

keybind::keybind(std::string name) noexcept
    : m_name(std::move(name))
{
}

keybind::keybind(const keycode& key) noexcept
    : m_key(key)
{
}

void keybind::set_name(const std::string& name) noexcept
{
    m_name = name;
}

void keybind::set_key(const keycode& key) noexcept
{
    m_key = key;
}

const std::string& keybind::get_name() const noexcept
{
    return m_name;
}

const keycode& keybind::get_key() const noexcept
{
    return m_key;
}

std::string keybind::to_string() const noexcept
{
    return std::string(std::ranges::find_if(key_map, [this](const auto& pair)
    {
        return pair.code == m_key;
    })->name);
}

bool keybind::catch_key()
{
    const auto& io = ImGui::GetIO();

    if (ImGui::IsKeyPressed(ImGuiKey_Escape))
    {
        m_key = keycode::none;
        return true;
    }

    if (io.MouseWheel < 0.0f)
    {
        m_key = keycode::mouse_wheel_up;
        return true;
    }

    if (io.MouseWheel > 0.0f)
    {
        m_key = keycode::mouse_wheel_down;
        return true;
    }

    if (std::ranges::any_of(key_map, [this](const auto& key)
    {
        return GetKeyState(static_cast<int>(key.code)) & 0x8000;
    }))
    {
        m_key = std::ranges::find_if(key_map, [](const auto& key)
        {
            return GetKeyState(static_cast<int>(key.code)) & 0x8000;
        })->code;

        return true;
    }

    for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); ++i) {
        if (!ImGui::IsMouseClicked(i))
            continue;

        m_key = static_cast<keycode>(static_cast<int>(keycode::mouse_1) + i);
        return true;
    }

    if (const auto it = std::ranges::find_if(key_map, [this](const auto& key)
    {
        return GetKeyState(static_cast<int>(key.code)) & 0x8000;
    }); it != std::end(key_map) && (m_key == keycode::left_ctrl && GetKeyState(
        static_cast<int>(key_map[static_cast<size_t>(keycode::right_alt)].code)) & 0x8000))
    {
        m_key = keycode::right_alt;
        return true;
    }

    return false;
}
