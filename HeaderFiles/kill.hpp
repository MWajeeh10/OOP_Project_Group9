#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
// #include "tokens.hpp"

class Kill{
    public:
        bool hasKilled = false;

        void killToken();
};
