#include <iostream>
#include "music_recommender.h" //to connect with the recommendation files
using namespace std;

int getIntegerInput() {
    int choice;

    while (true) {
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else {
            cin.ignore(10000, '\n');
            return choice;
        }
    }
}

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

        genreChoice = getIntegerInput();

        if (genreChoice == 0) { 
            cout << "\nReturning to main menu..." << endl; 
            break; 
        } 

        Recommendation rec = getRecommendation(genreChoice); 
        
        cout << "\n------------------------------------------" << endl; 
        cout << "             Your Recommendation     " << endl; 
        cout << "------------------------------------------" << endl; 


        if (rec.found) { 
            cout << "Song: " << rec.song << endl; 
            cout << "Artist: " << rec.artist << endl; 
            cout << "Description: " << rec.description << endl; 
        } 
        else { cout << rec.description << endl; } 

        cout << "------------------------------------------" << endl; 

        cout << "\nPress 0 to return to main menu or 1 to get another recommendation: ";

        nextChoice = getIntegerInput();

        if (nextChoice == 0) {
            cout << "\nReturning to main menu..." << endl;
            break;
        } else if (nextChoice == 1) {
            cout << "\nGetting another recommendation..." << endl;
        } else {
            cout << "Invalid input. Returning to main menu..." << endl;
            break;
        }
    }
}


void aboutSpotify() {
    int choice;

    cout << "\n========================================" << endl; 
    cout << "            ABOUT SPOTIFY" << endl; 
    cout << "========================================" << endl;
    cout << "Spotify is a digital music service that " << endl;
    cout << "gives you access to millions of songs." << endl;

    cout << "\n Press 0 to return to main menu: ";
    choice = getIntegerInput();

    while (choice != 0) {
        cout << "Invalid input. Please press 0 to return to main menu: ";
        choice = getIntegerInput();
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        choice = getIntegerInput();

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
