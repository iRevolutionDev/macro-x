#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"

#include "imgui_hotkey.hpp"
#include "keybind.hpp"

void ImGui::Hotkey(const char* label, keybind& keybind, const float sameline_offset, const ImVec2& size_arg)
{
    PushID(label);

    TextUnformatted(label);
    SameLine(sameline_offset);

    static std::string text(keybind.to_string());

    if (Button(text.c_str(), size_arg))
    {
        keybind.set_waiting_for_key(true);
        text = "Press any key to bind";
    }

    if (keybind.is_waiting_for_key() && keybind.catch_key())
    {
        keybind.set_waiting_for_key(false);
        text = keybind.to_string();
    }

    PopID();
}

void ImGui::Hotkey(const std::string& label, keybind& keybind, const float sameline_offset, const ImVec2& size_arg)
{
    Hotkey(label.c_str(), keybind, sameline_offset, size_arg);
}