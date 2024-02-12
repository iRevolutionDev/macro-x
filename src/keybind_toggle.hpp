#pragma once
#include "keybind.hpp"

class keybind_toggle final : public keybind
{
public:
    using keybind::keybind;

private:
    bool m_enabled = false;
};
