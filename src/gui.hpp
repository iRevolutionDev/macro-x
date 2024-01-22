#pragma once
#include "layer.hpp"

class gui final : public Sirius::layer
{
public:
    void on_render() override
    {
        ImGui::Begin("MacroX");
        ImGui::End();
    }
};
