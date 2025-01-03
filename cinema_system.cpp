#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// Structure to store movie information
struct Movie {
    string title;
    string genre;
    int year;
};

// Function prototypes
void displayMenu();
void createMovie(vector<Movie>& movies);
void displayMovies(const vector<Movie>& movies);
void searchMovie(const vector<Movie>& movies);
void updateMovie(vector<Movie>& movies);
void deleteMovie(vector<Movie>& movies);
void clearScreen();
void waitForInput();

int main() {
    vector<Movie> movies;
    int choice;

    while (true) {
        clearScreen();
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createMovie(movies);
                break;
            case 2:
                displayMovies(movies);
                break;
            case 3:
                searchMovie(movies);
                break;
            case 4:
                updateMovie(movies);
                break;
            case 5:
                deleteMovie(movies);
                break;
            case 6:
                cout << "Thank you for using Cinema Management System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                waitForInput();
        }
    }
    return 0;
}

void displayMenu() {
    cout << "\n=== Cinema Management System ===" << endl;
    cout << "1. Create Movie" << endl;
    cout << "2. See Movies" << endl;
    cout << "3. Search Movie" << endl;
    cout << "4. Update Movie" << endl;
    cout << "5. Delete Movie" << endl;
    cout << "6. Exit" << endl;
}

void createMovie(vector<Movie>& movies) {
    Movie movie;
    clearScreen();
    cout << "=== Create Movie ===" << endl;
    cout << "Enter movie title: ";
    getline(cin, movie.title);
    cout << "Enter movie genre: ";
    getline(cin, movie.genre);
    cout << "Enter movie year: ";
    cin >> movie.year;
    
    movies.push_back(movie);
    cout << "\nMovie added successfully!" << endl;
    waitForInput();
}

void displayMovies(const vector<Movie>& movies) {
    clearScreen();
    cout << "=== Movie List ===" << endl;
    
    if (movies.empty()) {
        cout << "No movies available." << endl;
    } else {
        // Create a copy of movies to sort
        vector<Movie> sortedMovies = movies;
        sort(sortedMovies.begin(), sortedMovies.end(), 
             [](const Movie& a, const Movie& b) { return a.title < b.title; });
        
        for (const auto& movie : sortedMovies) {
            cout << "\nTitle: " << movie.title << endl;
            cout << "Genre: " << movie.genre << endl;
            cout << "Year: " << movie.year << endl;
            cout << "------------------------" << endl;
        }
    }
    waitForInput();
}

void searchMovie(const vector<Movie>& movies) {
    clearScreen();
    cout << "=== Search Movie ===" << endl;
    string searchTitle;
    cout << "Enter movie title to search: ";
    getline(cin, searchTitle);
    
    bool found = false;
    for (const auto& movie : movies) {
        if (movie.title == searchTitle) {
            cout << "\nMovie found!" << endl;
            cout << "Title: " << movie.title << endl;
            cout << "Genre: " << movie.genre << endl;
            cout << "Year: " << movie.year << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\nMovie not found!" << endl;
    }
    waitForInput();
}

void updateMovie(vector<Movie>& movies) {
    clearScreen();
    cout << "=== Update Movie ===" << endl;
    string searchTitle;
    cout << "Enter movie title to update: ";
    getline(cin, searchTitle);
    
    for (auto& movie : movies) {
        if (movie.title == searchTitle) {
            cout << "\nEnter new movie title (or press enter to keep current): ";
            string newTitle;
            getline(cin, newTitle);
            if (!newTitle.empty()) movie.title = newTitle;
            
            cout << "Enter new movie genre (or press enter to keep current): ";
            string newGenre;
            getline(cin, newGenre);
            if (!newGenre.empty()) movie.genre = newGenre;
            
            cout << "Enter new movie year (or 0 to keep current): ";
            int newYear;
            cin >> newYear;
            if (newYear != 0) movie.year = newYear;
            
            cout << "\nMovie updated successfully!" << endl;
            waitForInput();
            return;
        }
    }
    
    cout << "\nMovie not found!" << endl;
    waitForInput();
}

void deleteMovie(vector<Movie>& movies) {
    clearScreen();
    cout << "=== Delete Movie ===" << endl;
    string searchTitle;
    cout << "Enter movie title to delete: ";
    getline(cin, searchTitle);
    
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->title == searchTitle) {
            movies.erase(it);
            cout << "\nMovie deleted successfully!" << endl;
            waitForInput();
            return;
        }
    }
    
    cout << "\nMovie not found!" << endl;
    waitForInput();
}

void clearScreen() {
    system("cls");
}

void waitForInput() {
    cout << "\nPress Enter to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
