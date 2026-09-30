# LDCW6123-Spotify-Innovation-Project

# Music Recommendation Assistant

**Course:** LDCW6123 - Fundamentals of Digital Competence for Programmer
**Assessment:** Group Project, Part 2 (Interactive C++ Program)
**Inspired by:** Spotify (Christensen's disruptive innovation model, Part 1)

## About

A simple console program that suggests a song and artist, with a short description, based on the user's preferred music genre. It is a simplified version of the personalised recommendation feature that helped Spotify improve and compete over time.

## Files

| File | Purpose |
|------|---------|
| `main.cpp` | Menu and user interaction: displays the menu, reads and validates input, and prints results. |
| `music_recommender.h` | Header file: declares the `Recommendation` struct and the logic functions. |
| `music_recommender.cpp` | Core logic: turns the chosen genre into a recommendation. |

## How it works

**Inputs:** the user's preferred music genre (a number 1-6, or the genre name).
**Outputs:** a suggested song, its artist, and a short description of why it was recommended.

### `music_recommender.cpp` (core logic)

- `getRecommendation(int choice)` uses a `switch` statement to match the genre number to a song, artist and description. The `default` case handles invalid input.
- `genreNameToChoice(const string&)` uses `if/else` to convert a typed genre name (for example "Jazz" or "hip hop") into the genre number. It is not case-sensitive and returns 0 for unknown genres.

### `main.cpp` (menu)

- `displayMenu()` shows the main menu.
- `musicRecommendation()` asks for a genre, calls the logic functions and prints the result.
- `aboutSpotify()` prints a short description of Spotify.
- `readNumber()` and `isNumber()` read input as text and check it is a number, so typing letters shows an error message instead of crashing or looping forever.

## Menu options

1. Get Music Recommendations
2. Learn About Spotify
3. Exit

## Supported genres

| Number | Genre | Recommendation |
|--------|-------|----------------|
| 1 | Pop | Blinding Lights - The Weeknd |
| 2 | Rock | Bohemian Rhapsody - Queen |
| 3 | Hip-Hop | HUMBLE. - Kendrick Lamar |
| 4 | Jazz | Take Five - The Dave Brubeck Quartet |
| 5 | Classical | Clair de Lune - Claude Debussy |
| 6 | Indie / Chill | Ocean Eyes - Billie Eilish |

## How to compile and run

Keep all three files in the same folder, then compile both `.cpp` files together:

```
g++ -std=c++11 -Wall -o music_app main.cpp music_recommender.cpp
./music_app
```

On Windows, run `music_app.exe` instead of `./music_app`.

## Example run

```
========================================
 WELCOME TO THE MUSIC RECOMMENDATION PROGRAM
========================================
Menu Options:
1. Get Music Recommendations
2. Learn About Spotify
3. Exit
Enter your choice: 1

Choose your preferred genre:
  1. Pop
  2. Rock
  3. Hip-Hop
  4. Jazz
  5. Classical
  6. Indie / Chill
Enter a number (1-6) or type a genre name: jazz

We recommend: "Take Five" by The Dave Brubeck Quartet
Why: A smooth jazz standard in an unusual 5/4 rhythm. Ideal for studying or relaxing.
```

## Input handling

- Invalid menu choices show "Invalid choice. Please try again."
- Invalid genres show "Invalid choice. Please pick a number from 1 to 6."
- Non-numeric input is handled safely without crashing.
