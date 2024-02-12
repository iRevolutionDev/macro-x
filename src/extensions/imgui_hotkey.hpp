#pragma once

#include "imgui.h"

class keybind;

namespace ImGui
{
    void Hotkey(const char* label, keybind& keybind, float sameline_offset = 0.0f, const ImVec2& size_arg = ImVec2(0, 0));
    void Hotkey(const std::string& label, keybind& keybind, float sameline_offset = 0.0f, const ImVec2& size_arg = ImVec2(0, 0));
}