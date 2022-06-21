#include "Control.hpp"

#include <algorithm>

void Control::vibrate() {}

jngl::Vec2 KetchupControl::getMovement() const {
	jngl::Vec2 mov;
	if (jngl::keyDown('a') || jngl::keyDown('A')) {
		mov += jngl::Vec2(-1, 0);
	}
	if (jngl::keyDown('d') || jngl::keyDown('D')) {
		mov += jngl::Vec2(1, 0);
	}

	auto controller = jngl::getConnectedControllers();
	if (controller.size() > 0)
	{
		auto x = controller[0]->state(jngl::controller::LeftStickX);
		mov.x += x;
		mov.x = fmaxf(mov.x, -1);
		mov.x = fminf(mov.x, 1);
	}

	return mov;
}

jngl::Vec2 MajoControl::getMovement() const {
	jngl::Vec2 mov;
	if (jngl::keyDown(jngl::key::Left)) {
		mov += jngl::Vec2(-1, 0);
	}
	if (jngl::keyDown(jngl::key::Right)) {
		mov += jngl::Vec2(1, 0);
	}

	auto controller = jngl::getConnectedControllers();
	if (!controller.empty()) {
		auto x = controller[0]->state(jngl::controller::RightStickX);
		mov.x += x;
		mov.x = fmaxf(mov.x, -1);
		mov.x = fminf(mov.x, 1);
	}

	return mov;
}
