#pragma once

class Token {
private:
    int _x, _y;  // Current coordinates of the token
    int _index;  // Index to track the current position in the movement array
    int _movement_array_size;  // Size of the movement array

public:
    // Constructor
    Token(int initialX, int initialY, int movementArraySize)
        : _x(initialX), _y(initialY), _index(0), _movement_array_size(movementArraySize) {}

    // Move the token to the next position in the movement array
    void moveToken() {
        // Check if the index is within the bounds of the movement array
        if (_index < _movement_array_size - 1) {
            _index++;
            _x = token_movement_array[_index][0];
            _y = token_movement_array[_index][1];
        }
    }

    // Getters for the current coordinates
    int getX() const { return _x; }
    int getY() const { return _y; }
};

// Example usage in your PlayerSelectionScreen class
class PlayerSelectionScreen {
private:
    Token playerToken;  // Replace with your actual constructor parameters

public:
    // Existing member functions...

    void token_move() {
        // Move the token based on your logic
        playerToken.moveToken();
    }
};
