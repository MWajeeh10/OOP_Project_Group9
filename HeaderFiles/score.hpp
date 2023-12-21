// score_calculator.hpp
#pragma once

#include <unordered_map>
#include <iostream>
#include "tokens.hpp"

class Token;  // Forward declaration

class ScoreCalculator {
public:
    // Increment the score for the specified token
    void operator+=(Token* token);

    // Get the score for the specified token
    int operator[](Token* token) const;

    // Print scores for all tokens
    // void printScores() const;

private:
    std::unordered_map<Token*, int> scores;
};
