#pragma once

#include <jngl.hpp>

class Control {
public:
	virtual ~Control() = default;

	/// Richtungsvektor
	virtual jngl::Vec2 getMovement() const = 0;
	virtual bool squeeze() const = 0;

	virtual void vibrate();
};

class KetchupControl : public Control {
public:
	jngl::Vec2 getMovement() const override;

	bool squeeze() const override {
		auto controller = jngl::getConnectedControllers();
		if (!controller.empty()) {
			auto squeeze = controller[0]->down(jngl::controller::LeftTrigger);
			if (squeeze)
			{
				return true;
			}
		}

		return jngl::keyDown('s') || jngl::keyDown('S');
	}
};

class MajoControl : public Control {
public:
	jngl::Vec2 getMovement() const override;

	bool squeeze() const override {
		auto controller = jngl::getConnectedControllers();
		if (controller.size() > 0)
		{
			auto squeeze = controller[0]->down(jngl::controller::RightTrigger);
			if (squeeze)
			{
				return true;
			}
		}

		return jngl::keyDown(jngl::key::Down) || jngl::keyDown(jngl::key::Space);
	}
};
