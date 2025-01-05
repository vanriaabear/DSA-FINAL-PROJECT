#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_MOVIES = 100;

// Arrays to store movie information
string movieTitles[MAX_MOVIES];
string movieGenres[MAX_MOVIES];
int movieYears[MAX_MOVIES];
int movieCount = 0;

// Function declarations
void createMovie();
void displayMovies();
void searchMovie();
void updateMovie();
void deleteMovie();
void clearScreen();
void waitForEnter();

int main() {
    int choice;

    while (true) {
        clearScreen();
        cout << "\n=== Movie Management System ===\n";
        cout << "1. Create Movie\n";
        cout << "2. See Movies\n";
        cout << "3. Search Movies\n";
        cout << "4. Update Movies\n";
        cout << "5. Delete Movie\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                updateMovie();
                break;
            case 5:
                deleteMovie();
                break;
            case 6:
                cout << "\nThank you for using Movie Management System!\n";
                return 0;
            default:
                cout << "\nInvalid choice! Press Enter to continue...";
                waitForEnter();
        }
    }
    return 0;
}

void clearScreen() {
    system("cls");
}

void waitForEnter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void createMovie() {
    clearScreen();
    if (movieCount >= MAX_MOVIES) {
        cout << "Movie database is full!\n";
        waitForEnter();
        return;
    }

    cout << "\n=== Create Movie ===\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter movie title: ";
    getline(cin, movieTitles[movieCount]);
    
    cout << "Enter movie genre: ";
    getline(cin, movieGenres[movieCount]);
    
    cout << "Enter movie year: ";
    cin >> movieYears[movieCount];

    movieCount++;
    cout << "\nMovie created successfully! Press Enter to continue...";
    waitForEnter();
}

void displayMovies() {
    clearScreen();
    cout << "\n=== Movie List ===\n";
    
    if (movieCount == 0) {
        cout << "No movies in database!\n";
    } else {
        for (int i = 0; i < movieCount; i++) {
            cout << "\nMovie " << (i + 1) << ":\n";
            cout << "Title: " << movieTitles[i] << "\n";
            cout << "Genre: " << movieGenres[i] << "\n";
            cout << "Year: " << movieYears[i] << "\n";
            cout << "------------------------\n";
        }
    }
    
    cout << "\nPress Enter to return to menu...";
    waitForEnter();
}

void searchMovie() {
    clearScreen();
    cout << "\n=== Search Movie ===\n";
    
    if (movieCount == 0) {
        cout << "No movies in database!\n";
        waitForEnter();
        return;
    }

    string searchTitle;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter movie title to search: ";
    getline(cin, searchTitle);

    bool found = false;
    for (int i = 0; i < movieCount; i++) {
        if (movieTitles[i] == searchTitle) {
            cout << "\nMovie found!\n";
            cout << "Title: " << movieTitles[i] << "\n";
            cout << "Genre: " << movieGenres[i] << "\n";
            cout << "Year: " << movieYears[i] << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nNo movie found!\n";
    }

    cout << "\nPress Enter to return to menu...";
    waitForEnter();
}

void updateMovie() {
    clearScreen();
    cout << "\n=== Update Movie ===\n";
    
    if (movieCount == 0) {
        cout << "No movies in database!\n";
        waitForEnter();
        return;
    }

    string updateTitle;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter movie title that you want to update: ";
    getline(cin, updateTitle);

    for (int i = 0; i < movieCount; i++) {
        if (movieTitles[i] == updateTitle) {
            cout << "\nEnter new movie title: ";
            getline(cin, movieTitles[i]);
            
            cout << "Enter new movie genre: ";
            getline(cin, movieGenres[i]);
            
            cout << "Enter new movie year: ";
            cin >> movieYears[i];

            cout << "\nMovie updated successfully!\n";
            waitForEnter();
            return;
        }
    }

    cout << "\nNo movie found!\n";
    waitForEnter();
}

void deleteMovie() {
    clearScreen();
    cout << "\n=== Delete Movie ===\n";
    
    if (movieCount == 0) {
        cout << "No movies in database!\n";
        waitForEnter();
        return;
    }

    string deleteTitle;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter movie title that you want to delete: ";
    getline(cin, deleteTitle);

    for (int i = 0; i < movieCount; i++) {
        if (movieTitles[i] == deleteTitle) {
            // Shift all elements after the deleted movie
            for (int j = i; j < movieCount - 1; j++) {
                movieTitles[j] = movieTitles[j + 1];
                movieGenres[j] = movieGenres[j + 1];
                movieYears[j] = movieYears[j + 1];
            }
            movieCount--;
            cout << "\nMovie deleted successfully!\n";
            waitForEnter();
            return;
        }
    }

    cout << "\nNo movie found!\n";
    waitForEnter();
}
