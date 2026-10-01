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
| `main.cpp` | Menu and user interaction: displays the menu, reads and validates input, and calls the other modules. |
| `music_recommender.h` | Header file: declares the `Recommendation` struct and the logic functions. |
| `music_recommender.cpp` | Core logic: turns the chosen genre into a recommendation. |
| `output_display.h` | Header file: declares the function that displays the recommendation result. |
| `output_display.cpp` | Output formatting: prints the recommendation (or an error message) as a formatted box on screen. |
| `.vscode/tasks.json` | VS Code build task that compiles the program with `g++`. |

## How it works

**Inputs:** the user's preferred music genre (a number 1-6, or the genre name).
**Outputs:** a suggested song, its artist, and a short description of why it was recommended.

The program is split into three parts, each with one job:

1. **Input and menu** (`main.cpp`): collects and validates what the user types.
2. **Logic** (`music_recommender.cpp`): decides which song to recommend.
3. **Output** (`output_display.cpp`): shows the result to the user.

### `music_recommender.cpp` (core logic)

- `getRecommendation(int choice)` uses a `switch` statement to match the genre number to a song, artist and description. The `default` case handles invalid input.
- `genreNameToChoice(const string&)` uses `if/else` to convert a typed genre name (for example "Jazz" or "hip hop") into the genre number. It is not case-sensitive and returns 0 for unknown genres.

### `output_display.cpp` (output display)

- `displayRecommendationResult(const Recommendation& rec, const string& genreName)` takes the `Recommendation` produced by the logic and prints it. The `genreName` parameter is optional (it defaults to an empty string).
- **If a recommendation was found** (`rec.found` is true), it prints a "YOUR MUSIC RECOMMENDATION" box showing the selected genre (if provided), song title, artist and description, followed by "Enjoy your music on Spotify!".
- **If no recommendation was found** (`rec.found` is false), it prints a "RECOMMENDATION ERROR" box with the error message stored in `rec.description`, then returns early.
- Keeping all printing in this file separates the display from the logic, so the layout can be changed without touching the recommendation code.

### `main.cpp` (menu)

- `displayMenu()` shows the main menu.
- `musicRecommendation()` asks for a genre, calls the logic functions and passes the result to `displayRecommendationResult()` to print it.
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

Keep all the source files in the same folder, then compile all three `.cpp` files together:

```
g++ -std=c++11 -Wall -o music_app main.cpp music_recommender.cpp output_display.cpp
./music_app
```

On Windows, run `music_app.exe` instead of `./music_app`.

**Using VS Code:** press `Ctrl+Shift+B` to run the "Build Spotify Program" task, which builds `program.exe`. Make sure `output_display.cpp` is listed in the `args` of `.vscode/tasks.json`, otherwise the build fails with an "undefined reference" error:

```json
"args": [
    "main.cpp",
    "music_recommender.cpp",
    "output_display.cpp",
    "-o",
    "program.exe"
]
```

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

==================================================
             YOUR MUSIC RECOMMENDATION
==================================================
 Selected Genre : Jazz
 Song Title     : Take Five
 Artist         : The Dave Brubeck Quartet
 Description    : A smooth jazz standard in an unusual 5/4 rhythm. Ideal for studying or relaxing.
==================================================
 Enjoy your music on Spotify!
```

## Input handling

- Invalid menu choices show "Invalid choice. Please try again."
- Invalid genres show a "RECOMMENDATION ERROR" box with the message "Invalid choice. Please pick a number from 1 to 6."
- Non-numeric input is handled safely without crashing.
