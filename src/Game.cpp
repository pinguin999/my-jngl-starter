#include "Game.hpp"

#include "engine/Fade.hpp"
#include "Control.hpp"
#include "Options.hpp"
#include "GameObject.hpp"
#include "Ball.hpp"

#include <cmath>

Game::Game() {
	jngl::setBackgroundColor(jngl::Color(0, 0, 0));

	gameObjects.emplace_back(std::make_shared<Ball>(jngl::Vec2(0, 0)));
}

void Game::step() {
	for (auto it = gameObjects.begin(); it != gameObjects.end();) {
		if ((*it)->step()) {
			++it;
		} else {
			it = gameObjects.erase(it);
		}
	}

	if (jngl::keyPressed(jngl::key::Return) && gameOver) {
		jngl::setWork<Fade>(std::make_shared<Game>());
	}
}

void Game::draw() const {
	jngl::setSpriteColor(255, 255, 255);

	for (const auto& gameObject : gameObjects) {
		gameObject->draw();
	}
}

bool Game::hasEnded() const {
	return false;
}
