#pragma once

#include "GameObject.hpp"

#include <jngl.hpp>

class Ball : public GameObject {
public:
	Ball(jngl::Vec2 position);
	bool step() override;
	void draw() const override;

private:
	jngl::Sprite sprite{"Icon"};
    jngl::Vec2 position;
};
