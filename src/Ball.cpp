#include "ball.hpp"

Ball::Ball(const jngl::Vec2 position) :position(position) {

}

bool Ball::step() {
	return true;
}

void Ball::draw() const {
	jngl::pushMatrix();
	jngl::translate(position);
	sprite.draw();
	jngl::popMatrix();
}
