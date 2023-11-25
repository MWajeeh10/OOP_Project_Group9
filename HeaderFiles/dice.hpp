#include<SDL.h>
#include<iostream>

enum Color {
    Red,
    Green,
    Blue,
    Yellow
};

class Dice{
    public:
    // Constructor that takes the color of the dice as an argument
    Dice(Color color);
    // Rolls the dice, simulating a dice roll and updating the dice's state and position accordingly
    void roll();

    // / Returns the current state of the dice (In_home or Out_home)
    DiceState getState() const;

    //Returns the current position of the dice on the playing field (1 to 56)
    int getPosition() const;

    private:
    enum DiceState{
        In_home;
        Out_home;
    }

    //Current state of the dice
    DiceState state;

    //current place of dice on the field
    int position;

    //Color of the dice
    Color color;

}