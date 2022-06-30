#pragma once

#include "GameObject.hpp"

#include <jngl.hpp>

class Ball : public GameObject {
public:
	Ball(jngl::Vec2 position);
	bool step() override;
	void draw() const override;

private:
    jngl::Vec2 velocity = jngl::Vec2(1,0);
};
