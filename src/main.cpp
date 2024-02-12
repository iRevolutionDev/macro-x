#include <Sirius/main.hpp>

#include "Sirius/application.hpp"
#include "gui.hpp"

Sirius::window* Sirius::create_window(int, char**)
{
    const auto current_window = new window(
        window_info{
            .title = "Macro X",
            .width = 800,
            .height = 600
        }
    );

    const auto app = new application();

    app->push_layer<gui>();

    current_window->set_app(app);
    return current_window;
}
