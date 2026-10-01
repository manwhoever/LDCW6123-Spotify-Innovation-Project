#include <iostream>
#include "music_recommender.h" //to connect with the recommendation files
#include "output_display.h"
using namespace std;

void displayMenu() {
    cout << "\n========================================" << endl; 
    cout << " WELCOME TO THE MUSIC RECOMMENDATION PROGRAM" << endl; 
    cout << "========================================" << endl;    
    cout << "Menu Options:" << endl;
    cout << "1. Get Music Recommendations" << endl;
    cout << "2. Learn About Spotify" << endl;
    cout << "3. Exit" << endl;
}

void musicRecommendation() {
   std::string genreInput;
    std::cout << "\nEnter a genre (Pop, Rock, Hip-Hop, Jazz, Classical, Indie/Chill): ";
    std::cin >> genreInput;

    // Convert the user's string input to Member 2's choice integer (1-6)
    int choice = genreNameToChoice(genreInput);

    // Get the recommendation struct from Member 2
    Recommendation rec = getRecommendation(choice);

    // Display the result using your output display module
    if (rec.found) {
        displayRecommendationResult(rec, genreInput);
    } else {
        std::cout << rec.description << std::endl; // Displays "Invalid choice..."
    }
}
void aboutSpotify() {
    cout << "About Spotify: Spotify is a digital music service that gives you access to millions of songs." << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                musicRecommendation();
                break;
            case 2:
                aboutSpotify();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
