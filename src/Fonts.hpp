#pragma once

#include "engine/Singleton.hpp"

#include <jngl/font.hpp>

class Fonts : public Singleton<Fonts> {
public:
	jngl::Font logo{ "Poppins-Bold.ttf", 140 };
	jngl::Font headline{ "Poppins-Bold.ttf", 100 };
	jngl::Font normal{ "Poppins-Bold.ttf", 60 };
	jngl::Font small{ "Poppins-Bold.ttf", 40 };
};
