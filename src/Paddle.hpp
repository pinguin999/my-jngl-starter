#pragma once

#include "GameObject.hpp"
#include "Control.hpp"

#include <jngl.hpp>

class Paddle : public GameObject {
public:
	Paddle(jngl::Vec2 position, int playerNr, std::unique_ptr<Control> control);
	bool step() override;
	void draw() const override;

private:
    const int playerNr;
	std::unique_ptr<Control> control;
};
