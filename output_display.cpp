//output display implementation 

#include "output_display.h"
#include <iostream>

using namespace std;

void displayRecommendationResult(const Recommendation& rec, const string& genreName) {
    if (!rec.found) {
        cout << "\n==================================================" << endl;
        cout << "               RECOMMENDATION ERROR               " << endl;
        cout << "==================================================" << endl;
        cout << " Message: " << rec.description << endl;
        cout << "==================================================\n" << endl;
        return;
    }

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