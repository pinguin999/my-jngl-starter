#pragma once

#include "engine/Singleton.hpp"

class Options : public Singleton<Options> {
public:
	Options();

	void save() const;

	bool sound = true;
	bool music = true;
};
