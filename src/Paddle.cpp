#include "Paddle.hpp"
#include "constants.hpp"

Paddle::Paddle(const jngl::Vec2 position, int playerNr, std::unique_ptr<Control> control) : playerNr(playerNr), control(std::move(control)) {
    this->position = position;
}

bool Paddle::step() {
	// Paddle logic goes here
	position += control->getMovement() * 5;

	int height = jngl::getScreenHeight() / 2;
	position.y = fmaxf(position.y, -height);
	position.y = fminf(position.y, height);
	return true;
}

void Paddle::draw() const {
	jngl::pushMatrix();
	jngl::setColor(jngl::Color(255, 255, 255));
	// Normal drawRect position is top left corner
	// We want to draw from the rect middle
	jngl::drawRect(position - jngl::Vec2(PADDLE_W / 2, PADDLE_H / 2), jngl::Vec2(PADDLE_W, PADDLE_H));
	jngl::popMatrix();
}
