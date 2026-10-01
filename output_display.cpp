//output display implementation 

#include "output_display.h"
#include <iostream>

using namespace std;

//------------ Displays either the music recommendation or an error message ------------
void displayRecommendationResult(const Recommendation& rec, const string& genreName) {

    // Display an error message if no valid recommendation was found
    if (!rec.found) {
        cout << "\n==================================================" << endl;
        cout << "               RECOMMENDATION ERROR               " << endl;
        cout << "==================================================" << endl;
        cout << " Message: " << rec.description << endl;
        cout << "==================================================\n" << endl;
        return;
    }

    // Display the recommended song details to the user
    cout << "\n==================================================" << endl;
    cout << "             YOUR MUSIC RECOMMENDATION            " << endl;
    cout << "==================================================" << endl;
    if (!genreName.empty()) {
        cout << " Selected Genre : " << genreName << endl;
    }
    cout << " Song Title     : " << rec.song << endl;
    cout << " Artist         : " << rec.artist << endl;
    cout << " Description    : " << rec.description << endl;
    cout << "==================================================" << endl;
    cout << " Enjoy your music on Spotify!\n" << endl;
}