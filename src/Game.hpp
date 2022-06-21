#pragma once
#include "jngl.hpp"

class GameObject;

class Game : public jngl::Work, public std::enable_shared_from_this<Game> {
public:
	Game();
	void step() override;
	void draw() const override;
	bool hasEnded() const;

private:
	std::vector<std::shared_ptr<GameObject>> gameObjects;
	bool gameOver = false;
};
