// music_recommender.h
// Declarations for the recommendation logic (Part 2 - LDCW6123)

#ifndef MUSIC_RECOMMENDER_H
#define MUSIC_RECOMMENDER_H

#include <string>

// Result of one recommendation
struct Recommendation {
    std::string song;
    std::string artist;
    std::string description;
    bool found;
};

// Core logic: genre number (1-6) -> recommendation (switch statement)
Recommendation getRecommendation(int choice);

// Genre name (e.g. "Jazz") -> genre number, or 0 if unknown (if/else)
int genreNameToChoice(const std::string& genreInput);

#endif
