#pragma once

#include <jngl/work.hpp>

class Fade : public jngl::Work {
public:
	Fade(std::shared_ptr<jngl::Work>, int speed = 20);
	void step() override;
	void draw() const override;
private:
	std::shared_ptr<Work> work_;
	std::shared_ptr<jngl::Work> oldWork_;
	double fadeCount_;
	int speed_;
};
