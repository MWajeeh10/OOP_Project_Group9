// score_calculator.cpp
#include "score.hpp"
#include "tokens.hpp"  // Include the Token class definition

void ScoreCalculator::operator+=(Token* token) {
    // Increment the score for the specified token
    scores[token]++;
}

int ScoreCalculator::operator[](Token* token) const {
    // Get the score for the specified token
    auto it = scores.find(token);
    return (it != scores.end()) ? it->second : 0;
}

void ScoreCalculator::printScores() const {
    // Print scores for all tokens
    for (const auto& entry : scores) {
        Token* token = entry.first;
        int score = entry.second;
        // You can print or use the scores as needed
        std::cout << "Player score for token: " << score << std::endl;
    }
}
