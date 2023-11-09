#pragma once

class Screen {         //creating a screen
public:           
    //virtual because we have may have to override it in future
    virtual void handleEvents() = 0;   //handles user input events
    virtual void update() = 0;         //updates the state of the screen
    virtual void render() = 0;         //rendering of the screen
};