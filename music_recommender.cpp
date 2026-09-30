// recommender.cpp
// Core recommendation logic (Part 2 - LDCW6123)

#include "music_recommender.h"
#include <algorithm>
#include <cctype>
using namespace std;

// Convert text to lowercase so "Pop", "POP" and "pop" all match
static string toLower(string text) {
    transform(text.begin(), text.end(), text.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });
    return text;
}

// ---------------------------------------------------------------
// CORE LOGIC FUNCTION
// Takes the genre choice (1-6) and returns a recommendation.
// Uses a switch statement to pick the genre; the default case
// handles invalid input.
// ---------------------------------------------------------------
Recommendation getRecommendation(int choice) {
    Recommendation rec;
    rec.found = true;

    switch (choice) {
        case 1: // Pop
            rec.song = "Blinding Lights";
            rec.artist = "The Weeknd";
            rec.description = "An upbeat synth-pop track with a retro 80s feel. "
                              "Great for energetic moods and long drives.";
            break;
        case 2: // Rock
            rec.song = "Bohemian Rhapsody";
            rec.artist = "Queen";
            rec.description = "A classic rock epic that blends ballad, opera and hard rock. "
                              "Perfect if you enjoy bold, dramatic songs.";
            break;
        case 3: // Hip-Hop
            rec.song = "HUMBLE.";
            rec.artist = "Kendrick Lamar";
            rec.description = "A hard-hitting hip-hop track with sharp lyrics and a heavy beat. "
                              "Good for workouts and focus.";
            break;
        case 4: // Jazz
            rec.song = "Take Five";
            rec.artist = "The Dave Brubeck Quartet";
            rec.description = "A smooth jazz standard in an unusual 5/4 rhythm. "
                              "Ideal for studying or relaxing.";
            break;
        case 5: // Classical
            rec.song = "Clair de Lune";
            rec.artist = "Claude Debussy";
            rec.description = "A calm, dreamy piano piece. "
                              "Perfect for winding down or concentrating.";
            break;
        case 6: // Indie / Chill
            rec.song = "Ocean Eyes";
            rec.artist = "Billie Eilish";
            rec.description = "A soft, mellow track with gentle vocals. "
                              "Suits quiet evenings and chill moods.";
            break;
        default:
            rec.found = false;
            rec.song = "";
            rec.artist = "";
            rec.description = "Invalid choice. Please pick a number from 1 to 6.";
            break;
    }
    return rec;
}

// Lets users type the genre name instead of a number.
// Returns the matching genre number, or 0 if the genre is unknown.
int genreNameToChoice(const string& genreInput) {
    string g = toLower(genreInput);

    if (g == "pop") return 1;
    else if (g == "rock") return 2;
    else if (g == "hip-hop" || g == "hiphop" || g == "hip hop" || g == "rap") return 3;
    else if (g == "jazz") return 4;
    else if (g == "classical") return 5;
    else if (g == "indie" || g == "chill") return 6;
    else return 0;
}
