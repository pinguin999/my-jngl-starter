#include "constants.hpp"
#include "Game.hpp"

#include <jngl/init.hpp>

class QuitWithEscape : public jngl::Job {
public:
	void step() override {
		if (jngl::keyPressed(jngl::key::Escape)) {
			jngl::quit();
		}
	}
	void draw() const override {
	}
};

jngl::AppParameters jnglInit() {
	jngl::AppParameters params;
	std::srand(std::time(nullptr));
	params.displayName = programDisplayName;
	params.screenSize = { 1920, 1080 };

	params.start = []() {
		jngl::setIcon("Icon");
		jngl::setFont("Poppins-Bold.ttf");
#ifndef NDEBUG
		jngl::addJob(std::make_shared<QuitWithEscape>());
#endif
		return std::make_shared<Game>();
	};

	return params;
}
