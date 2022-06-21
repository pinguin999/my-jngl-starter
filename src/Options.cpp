#include "Options.hpp"

#include <jngl.hpp>
#include <string>

Options::Options() {
	{
		std::istringstream tmp(jngl::readConfig("sound"));
		tmp >> sound;
	}
	{
		std::istringstream tmp(jngl::readConfig("music"));
		tmp >> music;
	}
}

void Options::save() const {
	jngl::writeConfig("sound", std::to_string(sound));
	jngl::writeConfig("music", std::to_string(music));
}
