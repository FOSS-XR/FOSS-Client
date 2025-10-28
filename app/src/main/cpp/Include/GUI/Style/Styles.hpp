#pragma once

#include <vector>
#include "Style.hpp"

class Styles {
public:
    inline static std::vector<Style> allStyles = {
            Style{
                    .styleName = "default",
                    .titleColor = "blue",
                    .buttonColor = "white",
                    .pointerColor = "white",
                    .enabledColor = "lime",
                    .disabledColor = "white"
            },
            Style{
                    .styleName = "rainbow"
            },
            Style{
                    .styleName = "red",
                    .titleColor = "red",
                    .buttonColor = "red",
                    .pointerColor = "white",
                    .enabledColor = "lime",
                    .disabledColor = "red"
            },
            Style{
                    .styleName = "blue",
                    .titleColor = "blue",
                    .buttonColor = "blue",
                    .pointerColor = "white",
                    .enabledColor = "green",
                    .disabledColor = "blue"
            }
    };
};
