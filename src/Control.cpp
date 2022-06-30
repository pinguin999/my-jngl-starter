#include "Control.hpp"

#include <algorithm>

void Control::vibrate() {}

jngl::Vec2 KetchupControl::getMovement() const {
	jngl::Vec2 mov;
	if (jngl::keyDown('w') || jngl::keyDown('W')) {
		mov += jngl::Vec2(0, -1);
	}
	if (jngl::keyDown('s') || jngl::keyDown('S')) {
		mov += jngl::Vec2(0, 1);
	}

	auto controller = jngl::getConnectedControllers();
	if (controller.size() > 0)
	{
		auto y = controller[0]->state(jngl::controller::LeftStickY);
		mov.y += y;
		mov.y = fmaxf(mov.y, -1);
		mov.y = fminf(mov.y, 1);
	}

	return mov;
}

jngl::Vec2 MajoControl::getMovement() const {
	jngl::Vec2 mov;
	if (jngl::keyDown(jngl::key::Up)) {
		mov += jngl::Vec2(0, -1);
	}
	if (jngl::keyDown(jngl::key::Down)) {
		mov += jngl::Vec2(0, 1);
	}

	auto controller = jngl::getConnectedControllers();
	if (!controller.empty()) {
		auto y = controller[0]->state(jngl::controller::RightStickY);
		mov.y += y;
		mov.y = fmaxf(mov.y, -1);
		mov.y = fminf(mov.y, 1);
	}

	return mov;
}
