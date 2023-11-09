#pragma once
#include "Screen.hpp"

class WelcomeScreen : public Screen {
public:
    WelcomeScreen();
    void handleEvents() override;
    void update() override;
    void render() override;
};