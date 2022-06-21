#pragma once

#include <memory>

template <class T> class Singleton {
public:
	~Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

	static T& handle() {
		if (!instance) {
			instance = std::make_unique<T>();
		}
		return *instance;
	}

	static void destroy() {
		instance.reset();
	}

protected:
	Singleton() = default;

private:
	static std::unique_ptr<T> instance;
};

template <class T> std::unique_ptr<T> Singleton<T>::instance;
