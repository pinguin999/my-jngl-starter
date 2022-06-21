#include "constants.hpp"

#include <jngl.hpp>

void printCentered(const std::string& text, double x, double y) {
	jngl::print(text, static_cast<int>((x - jngl::getTextWidth(text) / 2)),
	            static_cast<int>(y) - jngl::getFontSize() / 2);
}
