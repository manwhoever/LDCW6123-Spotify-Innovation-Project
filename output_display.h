//output display functions declarations

#ifndef OUTPUT_DISPLAY_H
#define OUTPUT_DISPLAY_H

#include "music_recommender.h"
#include <string>

//formats and displays the recommendation result nicely on screen
void displayRecommendationResult(const Recommendation& rec, const std::string& genreName = "");

#endif