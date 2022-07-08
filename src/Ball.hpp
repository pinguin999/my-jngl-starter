#pragma once

#include "GameObject.hpp"

#include <jngl.hpp>

class Paddle;

class Ball : public GameObject {
public:
	Ball(jngl::Vec2 position, std::shared_ptr<Paddle> left, std::shared_ptr<Paddle> right);
	bool step() override;
	void draw() const override;

private:
    jngl::Vec2 velocity = jngl::Vec2(4,5);
	std::shared_ptr<Paddle> left;
	std::shared_ptr<Paddle> right;
};
