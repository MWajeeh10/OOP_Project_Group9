#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "kill.hpp"

void Kill::killToken(){
    hasKilled = true;
}