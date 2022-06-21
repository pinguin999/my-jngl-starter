#include "GameObject.hpp"

#include "helper.hpp"

jngl::Vec2 GameObject::getPosition() const {
	return { position };
}

void GameObject::setPosition(const jngl::Vec2 position) {
	this->position = position;
}

int GameObject::getAmount() const {
	return 0;
}

double GameObject::getZIndex() const {
	return getPosition().y;
}
