#pragma once

#include <string>

const std::string programDisplayName = "JNGL Example Game";

constexpr int BALL_RADIUS = 20;

constexpr int PADDLE_W = 50;
constexpr int PADDLE_H = 200;

void printCentered(const std::string& text, double x, double y);
