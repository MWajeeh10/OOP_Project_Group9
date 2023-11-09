#pragma once
#include "Screen.hpp"

class RulesScreen : public Screen {
public:
    RulesScreen();
    void handleEvents() override;
    void update() override;
    void render() override;
};