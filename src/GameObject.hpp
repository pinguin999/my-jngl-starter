#pragma once

#include <jngl/Vec2.hpp>

/// Basisklasse für die physischen Objekte im Spiel
class GameObject {
public:
	/// true zurückgeben damit das Objekt entfernt wird
	virtual bool step() = 0;

	virtual void draw() const = 0;

	virtual jngl::Vec2 getPosition() const;
	void setPosition(jngl::Vec2 position);

	virtual ~GameObject() = default;

	virtual int getAmount() const;

	virtual double getZIndex() const;

protected:
	jngl::Vec2 position;
};
