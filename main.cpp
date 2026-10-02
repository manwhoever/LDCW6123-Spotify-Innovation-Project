#include <iostream>
#include <cstdlib>   // for exit()
#include "music_recommender.h" // Connects to the music recommendation functions
#include "output_display.h" // Connects to the output display functions
using namespace std;

// Gets an integer from the user and validates that it's within the allowed range
int getIntegerInput(int min, int max) {
    int choice;

    while (true) {
        cin >> choice;

        if (cin.fail()) {
            if (cin.eof()) { // Handle end-of-file (Ctrl+D or Ctrl+Z)
                cout << "\nEnd of input detected. Exiting the program." << endl;
                exit(0);
            }
            cin.clear(); // Clear the error state when the user enters a non-numeric value
            cin.ignore(10000, '\n'); // Remove the invalid input from the input buffer
            cout << "Invalid character. Please enter a number from "
                 << min << " to " << max << ": ";
        }
        else if (cin.peek() != '\n') { // Check for extra characters after the number
            cin.ignore(10000, '\n'); // Remove the extra characters from the input buffer
            cout << "Invalid input. Please enter a number from "
                 << min << " to " << max << ": ";
        }
        else if (choice < min || choice > max) {
            cin.ignore(10000, '\n'); // Reject numbers outside the range
            cout << "Invalid choice. Please enter a number from "
                 << min << " to " << max << ": ";
        }
        else {
            cin.ignore(10000, '\n'); // Valid input received
            return choice;
        }
    }
}

// ----------------------------------------- Displays the MAIN MENU options ------------------------------------------
void displayMenu() {
    cout << "\n========================================" << endl; 
    cout << " WELCOME TO THE MUSIC RECOMMENDATION PROGRAM" << endl; 
    cout << "========================================" << endl;    
    cout << "Menu Options:" << endl;
    cout << "1. Get Music Recommendations" << endl;
    cout << "2. Learn About Spotify" << endl;
    cout << "3. Exit" << endl;
}

// Allows the user to choose a genre and receive a music recommendation
void musicRecommendation() {
    int genreChoice; 
    int nextChoice;

    while (true) { 
        cout << "\n========================================" << endl; 
        cout << "    MUSIC RECOMMENDATIONS" << endl; 
        cout << "========================================" << endl; 
        cout << "Choose a genre:" << endl; cout << "1. Pop" << endl; 
        cout << "2. Rock" << endl; cout << "3. Hip-Hop" << endl; 
        cout << "4. Jazz" << endl; cout << "5. Classical" << endl; 
        cout << "6. Indie / Chill" << endl; 
        cout << "0. Back to Main Menu" << endl; 
        cout << "Enter your choice: "; 

        genreChoice = getIntegerInput(0, 6); // Get and validate the user's genre selection

        if (genreChoice == 0) { 
            cout << "\nReturning to main menu..." << endl; 
            return; 
        }

        Recommendation rec = getRecommendation(genreChoice); 
        
        displayRecommendationResult(rec, "");

        while (true) {
            cout << "\nPress 0 to return to main menu or 1 to get another recommendation: ";

            nextChoice = getIntegerInput(0, 1); // Validate whether the user wants another recommendation

            if (nextChoice == 0) {
                cout << "\nReturning to main menu..." << endl;
                return;
            }
            else {
                cout << "\nGetting another recommendation..." << endl;
                break;
            }
        }

    }
}

//----------------------------------------- Displays basic information about Spotify -----------------------------------------
void aboutSpotify() {
    int choice;

    cout << "\n========================================" << endl; 
    cout << "            ABOUT SPOTIFY" << endl; 
    cout << "========================================" << endl;
    cout << "Spotify is a digital music service that " << endl;
    cout << "gives you access to millions of songs." << endl;

    cout << "\nPress 0 to return to main menu: ";
    choice = getIntegerInput(0, 0);
}

// Main function that controls the program menu
int main() {
    int choice; 
    do {
        displayMenu();
        cout << "Enter your choice: ";
        choice = getIntegerInput(1, 3); // Get and validate the user's main menu choice

        switch (choice) {
            case 1:
                musicRecommendation(); // Open the music recommendation feature
                break;
            case 2:
                aboutSpotify(); // Display information about Spotify
                break;
            case 3:
                cout << "Exiting the program." << endl; // End the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
