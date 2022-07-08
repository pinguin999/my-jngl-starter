#include "Ball.hpp"

Ball::Ball(const jngl::Vec2 position){
	this->position = position;
}

bool Ball::step() {
	// Ball logic goes here
	position = position + velocity;

	int width = jngl::getScreenWidth();
	if (position.x > width / 2 || position.x < -width / 2)
	{
		velocity.x = velocity.x * -1.0;
	}

	int height = jngl::getScreenHeight();
	if (position.y > height / 2 || position.y < -height / 2)
	{
		velocity.y = velocity.y * -1.0;
	}

	return true;
}

void Ball::draw() const {
	jngl::pushMatrix();
	jngl::setColor(jngl::Color(255, 255, 255));
	jngl::drawCircle(position, 20);
	jngl::popMatrix();
}
